#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "error.h"
#include "exchange_info.h"
#include "json.h"
#include "spot_sbe/BoolEnum.h"
#include "spot_sbe/ErrorResponse.h"
#include "spot_sbe/ExchangeInfoResponse.h"
#include "spot_sbe/MessageHeader.h"

using spot_sbe::BoolEnum;
using spot_sbe::ErrorResponse;
using spot_sbe::ExchangeInfoResponse;
using spot_sbe::MessageHeader;

std::vector<char> read_payload(const int fd) {
    std::vector<char> payload;
    const size_t chunk_size = 64 * 1024;
    auto offset = 0;
    while (true) {
        payload.resize(payload.size() + chunk_size);
        const auto bytes = read(fd, payload.data() + offset, chunk_size);
        if (bytes < 0) {
            perror("read");
            exit(1);
        }
        if (bytes == 0) {
            break;
        }
        payload.resize(offset + bytes);
        offset += bytes;
    }
    return payload;
}

bool as_bool(const BoolEnum::Value bool_enum) {
    switch (bool_enum) {
        case BoolEnum::Value::False: {
            return false;
        }
        case BoolEnum::Value::True: {
            return true;
        }
        case BoolEnum::Value::NULL_VALUE: {
            fprintf(stderr, "Unexpected NULL_VALUE\n");
            exit(1);
        }
    }
    return false;
}

int main() {
    auto payload = read_payload(STDIN_FILENO);
    const MessageHeader message_header(payload.data(), payload.size());

    const auto template_id = message_header.templateId();
    if (template_id == ErrorResponse::sbeTemplateId()) {
        // A separate "ErrorResponse" message is returned for errors and its
        // format is expected to be backwards compatible across all schema IDs.
        auto decoder =
            message_from_header<ErrorResponse>(payload.data(), payload.size(), message_header);
        Error error(decoder);
        print_json(error);
        return 1;
    }
    const auto schema_id = message_header.schemaId();
    if (schema_id != ExchangeInfoResponse::sbeSchemaId()) {
        fprintf(stderr, "Unexpected schema ID %d\n", schema_id);
        return 1;
    }
    const auto version = message_header.version();
    if (version != ExchangeInfoResponse::sbeSchemaVersion()) {
        fprintf(stderr, "Warning: Unexpected version %d\n", version);
        // Schemas with the same ID are expected to be backwards compatible.
    }
    if (template_id != ExchangeInfoResponse::sbeTemplateId()) {
        fprintf(stderr, "Unexpected template ID %d\n", template_id);
        return 1;
    }

    auto exchange_info =
        message_from_header<ExchangeInfoResponse>(payload.data(), payload.size(), message_header);

    ExchangeInfo result;
    auto& rate_limits = exchange_info.rateLimits();
    result.rate_limits.reserve(rate_limits.count());
    rate_limits.forEach([&](const auto& rate_limit) {
        // Read buffer into intermediate variables to ensure the buffer is being read sequentially.
        const auto rate_limit_type = rate_limit.rateLimitType();
        const auto interval = rate_limit.interval();
        const auto interval_num = rate_limit.intervalNum();
        const auto limit = rate_limit.rateLimit();
        result.rate_limits.push_back(RateLimit{rate_limit_type, interval, interval_num, limit});
    });

    auto& exchange_filters = exchange_info.exchangeFilters();
    result.exchange_filters.reserve(exchange_filters.count());
    exchange_filters.forEach([&](auto& filter) {
        const auto filter_size = filter.filterLength();
        char* const filter_data = const_cast<char*>(filter.filter());
        const MessageHeader message_header(filter_data, filter_size);
        result.exchange_filters.emplace_back(
            make_exchange_filter(message_header, filter_data, filter_size));
    });

    auto& symbols = exchange_info.symbols();
    result.symbols.reserve(symbols.count());
    symbols.forEach([&](auto& symbol) {
        const auto status = symbol.status();
        const auto base_asset_precision = symbol.baseAssetPrecision();
        const auto quote_asset_precision = symbol.quoteAssetPrecision();
        const auto base_commission_precision = symbol.baseCommissionPrecision();
        const auto quote_commission_precision = symbol.quoteCommissionPrecision();
        const OrderTypes order_types(symbol.orderTypes());
        const auto iceberg_allowed = as_bool(symbol.icebergAllowed());
        const auto oco_allowed = as_bool(symbol.ocoAllowed());
        const auto quote_order_qty_market_allowed = as_bool(symbol.quoteOrderQtyMarketAllowed());
        const auto allow_trailing_stop = as_bool(symbol.allowTrailingStop());
        const auto cancel_replace_allowed = as_bool(symbol.cancelReplaceAllowed());
        const auto is_spot_trading_allowed = as_bool(symbol.isSpotTradingAllowed());
        const auto is_margin_trading_allowed = as_bool(symbol.isMarginTradingAllowed());
        const auto default_self_trade_prevention_mode = symbol.defaultSelfTradePreventionMode();
        const SelfTradePreventionModes allowed_self_trade_prevention_modes(
            symbol.allowedSelfTradePreventionModes());
        auto& filters = symbol.filters();

        std::vector<SymbolFilter> symbol_filters;
        symbol_filters.reserve(filters.count());
        filters.forEach([&](auto& filter) {
            const auto filter_size = filter.filterLength();
            char* filter_data = const_cast<char*>(filter.filter());
            const MessageHeader message_header(filter_data, filter_size);
            symbol_filters.emplace_back(
                make_symbol_filter(message_header, filter_data, filter_size));
        });

        auto& permissions = symbol.permissions();
        std::vector<std::string> symbol_permissions;
        symbol_permissions.reserve(permissions.count());
        permissions.forEach([&](auto& permission) {
            symbol_permissions.push_back(permission.getPermissionAsString());
        });

        std::string symbol_str = symbol.getSymbolAsString();
        std::string base_asset = symbol.getBaseAssetAsString();
        std::string quote_asset = symbol.getQuoteAssetAsString();

        result.symbols.push_back(SymbolInfo{
            status,
            base_asset_precision,
            quote_asset_precision,
            base_commission_precision,
            quote_commission_precision,
            std::move(order_types),
            iceberg_allowed,
            oco_allowed,
            quote_order_qty_market_allowed,
            allow_trailing_stop,
            cancel_replace_allowed,
            is_spot_trading_allowed,
            is_margin_trading_allowed,
            default_self_trade_prevention_mode,
            allowed_self_trade_prevention_modes,
            std::move(symbol_filters),
            std::move(symbol_permissions),
            std::move(symbol_str),
            std::move(base_asset),
            std::move(quote_asset),
        });
    });

    auto& sors = exchange_info.sors();
    result.sors.reserve(sors.count());
    sors.forEach([&](auto& decoder) {
        auto& sor_symbols = decoder.sorSymbols();
        Sor sor;
        sor_symbols.forEach(
            [&](auto& symbol) { sor.symbols.push_back(symbol.getSymbolAsString()); });
        sor.base_asset = decoder.getBaseAssetAsString();
        result.sors.push_back(std::move(sor));
    });
    print_json(result);
    return 0;
}
