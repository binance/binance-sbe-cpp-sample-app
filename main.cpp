#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <optional>
#include <span>
#include <string>
#include <vector>

#include "account.h"
#include "error.h"
#include "exchange_info.h"
#include "get_order.h"
#include "json.h"
#include "post_order.h"
#include "spot_sbe/AccountResponse.h"
#include "spot_sbe/BoolEnum.h"
#include "spot_sbe/ErrorResponse.h"
#include "spot_sbe/ExchangeInfoResponse.h"
#include "spot_sbe/MessageHeader.h"
#include "spot_sbe/NewOrderResultResponse.h"
#include "spot_sbe/OrderResponse.h"
#include "spot_sbe/WebSocketResponse.h"
#include "web_socket_metadata.h"

using spot_sbe::AccountResponse;
using spot_sbe::BoolEnum;
using spot_sbe::ErrorResponse;
using spot_sbe::ExchangeInfoResponse;
using spot_sbe::MessageHeader;
using spot_sbe::NewOrderResultResponse;
using spot_sbe::OrderResponse;
using spot_sbe::WebSocketResponse;

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

Account decode_account(const std::span<char> payload, const MessageHeader& message_header) {
    auto account = message_from_header<AccountResponse>(payload, message_header);

    Account result;
    const auto commission_exponent = account.commissionExponent();
    const auto commission_rate_maker = account.commissionRateMaker();
    const auto commission_rate_taker = account.commissionRateTaker();
    const auto commission_rate_buyer = account.commissionRateBuyer();
    const auto commission_rate_seller = account.commissionRateSeller();

    result.commission_rates =
        CommissionRates{commission_rate_maker, commission_rate_taker, commission_rate_buyer,
                        commission_rate_seller, commission_exponent};

    result.can_trade = as_bool(account.canTrade());
    result.can_withdraw = as_bool(account.canWithdraw());
    result.can_deposit = as_bool(account.canDeposit());
    result.brokered = as_bool(account.brokered());
    result.require_self_trade_prevention = as_bool(account.requireSelfTradePrevention());
    result.prevent_sor = as_bool(account.preventSor());
    result.update_time = account.updateTime();  // SBE timestamps are in microseconds.
    result.account_type = account.accountType();

    const auto trade_group_id = account.tradeGroupId();
    if (trade_group_id != AccountResponse::tradeGroupIdNullValue()) {
        result.trade_group_id = trade_group_id;
    }

    result.uid = account.uid();

    auto& balances = account.balances();
    result.balances.reserve(balances.count());
    balances.forEach([&](auto& balance) {
        const auto balances_exponent = balance.exponent();
        const auto free = balance.free();
        const auto locked = balance.locked();
        auto asset = balance.getAssetAsString();
        result.balances.push_back(Balances{free, locked, asset, balances_exponent});
    });

    auto& permissions = account.permissions();
    result.permissions.reserve(permissions.count());
    permissions.forEach([&](auto& permission) {
        result.permissions.push_back(permission.getPermissionAsString());
    });

    auto& reduce_only_assets = account.reduceOnlyAssets();
    result.reduce_only_assets.reserve(reduce_only_assets.count());
    reduce_only_assets.forEach([&](auto& reduce_only_asset) {
        result.reduce_only_assets.push_back(reduce_only_asset.getAssetAsString());
    });
    return result;
}

ExchangeInfo decode_exchange_info(const std::span<char> payload,
                                  const MessageHeader& message_header) {
    auto exchange_info = message_from_header<ExchangeInfoResponse>(payload, message_header);

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
            make_exchange_filter(message_header, std::span{filter_data, filter_size}));
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
                make_symbol_filter(message_header, std::span{filter_data, filter_size}));
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
    return result;
}

GetOrder decode_get_order(const std::span<char> payload, const MessageHeader& message_header) {
    auto get_order = message_from_header<OrderResponse>(payload, message_header);

    GetOrder result;
    auto price_exponent = get_order.priceExponent();
    auto qty_exponent = get_order.qtyExponent();
    result.order_id = get_order.orderId();

    const auto order_list_id = get_order.orderListId();
    if (order_list_id != OrderResponse::orderListIdNullValue()) {
        result.order_list_id = order_list_id;
    }
    result.price = Decimal{get_order.price(), price_exponent};
    result.orig_qty = Decimal{get_order.origQty(), qty_exponent};
    result.executed_qty = Decimal{get_order.executedQty(), qty_exponent};
    result.cummulative_quote_qty = Decimal{get_order.cummulativeQuoteQty(), price_exponent};
    result.status = get_order.status();
    result.time_in_force = get_order.timeInForce();
    result.order_type = get_order.orderType();
    result.side = get_order.side();

    const auto stop_price = get_order.stopPrice();
    if (stop_price != OrderResponse::stopPriceNullValue()) {
        result.stop_price = Decimal{stop_price, price_exponent};
    }
    const auto trailing_delta = get_order.trailingDelta();
    if (trailing_delta != OrderResponse::trailingDeltaNullValue()) {
        result.trailing_delta = trailing_delta;
    }
    const auto trailing_time = get_order.trailingTime();
    if (trailing_time != OrderResponse::trailingTimeNullValue()) {
        result.trailing_time = trailing_time;
    }
    const auto iceberg_qty = get_order.icebergQty();
    if (iceberg_qty != OrderResponse::icebergQtyNullValue()) {
        result.iceberg_qty = Decimal{iceberg_qty, qty_exponent};
    }
    result.time = get_order.time();
    result.update_time = get_order.updateTime();
    result.is_working = as_bool(get_order.isWorking());

    const auto working_time = get_order.workingTime();
    if (working_time != OrderResponse::workingTimeNullValue()) {
        result.working_time = working_time;  // SBE timestamps are in microseconds.
    }
    result.orig_quote_order_qty = Decimal{get_order.origQuoteOrderQty(), price_exponent};

    const auto strategy_id = get_order.strategyId();
    if (strategy_id != OrderResponse::strategyIdNullValue()) {
        result.strategy_id = strategy_id;
    }
    const auto strategy_type = get_order.strategyType();
    if (strategy_type != OrderResponse::strategyTypeNullValue()) {
        result.strategy_type = strategy_type;
    }
    result.order_capacity = get_order.orderCapacity();
    result.working_floor = get_order.workingFloor();
    result.self_trade_prevention_mode = get_order.selfTradePreventionMode();
    const auto prevented_match_id = get_order.preventedMatchId();
    if (prevented_match_id != OrderResponse::preventedMatchIdNullValue()) {
        result.prevented_match_id = prevented_match_id;
    }
    const auto prevented_quantity = get_order.preventedQuantity();
    if (prevented_quantity != OrderResponse::preventedQuantityNullValue()) {
        result.prevented_quantity = Decimal{prevented_quantity, qty_exponent};
    }
    result.used_sor = get_order.usedSor();
    result.symbol = get_order.getSymbolAsString();
    result.client_order_id = get_order.getClientOrderIdAsString();
    return result;
}

NewOrder decode_post_order(const std::span<char> payload, const MessageHeader& message_header) {
    auto post_order = message_from_header<NewOrderResultResponse>(payload, message_header);

    NewOrder result;
    auto price_exponent = post_order.priceExponent();
    auto qty_exponent = post_order.qtyExponent();
    result.order_id = post_order.orderId();

    const auto order_list_id = post_order.orderListId();
    if (order_list_id != NewOrderResultResponse::orderListIdNullValue()) {
        result.order_list_id = order_list_id;
    }

    result.transaction_time = post_order.transactTime();  // SBE timestamps are in microseconds.
    result.price = Decimal{post_order.price(), price_exponent};
    result.orig_qty = Decimal{post_order.origQty(), qty_exponent};
    result.executed_qty = Decimal{post_order.executedQty(), qty_exponent};
    result.cummulative_quote_qty = Decimal{post_order.cummulativeQuoteQty(), price_exponent};
    result.status = post_order.status();
    result.time_in_force = post_order.timeInForce();
    result.order_type = post_order.orderType();
    result.side = post_order.side();

    const auto stop_price = post_order.stopPrice();
    if (stop_price != NewOrderResultResponse::stopPriceNullValue()) {
        result.stop_price = Decimal{stop_price, price_exponent};
    }

    const auto trailing_delta = post_order.trailingDelta();
    if (trailing_delta != NewOrderResultResponse::trailingDeltaNullValue()) {
        result.trailing_delta = trailing_delta;
    }

    const auto trailing_time = post_order.trailingTime();
    if (trailing_time != NewOrderResultResponse::trailingTimeNullValue()) {
        result.trailing_time = trailing_time;
    }

    const auto working_time = post_order.workingTime();
    if (working_time != NewOrderResultResponse::workingTimeNullValue()) {
        result.working_time = working_time;  // SBE timestamps are in microseconds.
    }

    const auto iceberg_qty = post_order.icebergQty();
    if (iceberg_qty != NewOrderResultResponse::icebergQtyNullValue()) {
        result.iceberg_qty = iceberg_qty;
    }

    const auto strategy_id = post_order.strategyId();
    if (strategy_id != NewOrderResultResponse::strategyIdNullValue()) {
        result.strategy_id = strategy_id;
    }

    const auto strategy_type = post_order.strategyType();
    if (strategy_type != NewOrderResultResponse::strategyTypeNullValue()) {
        result.strategy_type = strategy_type;
    }

    result.order_capacity = post_order.orderCapacity();
    result.working_floor = post_order.workingFloor();
    result.self_trade_prevention_mode = post_order.selfTradePreventionMode();

    const auto trade_group_id = post_order.tradeGroupId();
    if (trade_group_id != NewOrderResultResponse::tradeGroupIdNullValue()) {
        result.trade_group_id = trade_group_id;
    }

    const auto prevented_quantity = post_order.preventedQuantity();
    if (prevented_quantity != NewOrderResultResponse::preventedQuantityNullValue()) {
        result.prevented_quantity = Decimal{prevented_quantity, qty_exponent};
    }

    result.used_sor = post_order.usedSor();
    result.symbol = post_order.getSymbolAsString();
    result.client_order_id = post_order.getClientOrderIdAsString();
    return result;
}

Error decode_error_response(const std::span<char> payload, const MessageHeader& message_header) {
    auto decoder = message_from_header<ErrorResponse>(payload, message_header);
    return Error(decoder);
}

WebSocketMetadata decode_websocket_response(const std::span<char> payload,
                                            const MessageHeader& message_header) {
    auto decoder = message_from_header<WebSocketResponse>(payload, message_header);
    const bool deprecated = as_bool(decoder.sbeSchemaIdVersionDeprecated());
    if (deprecated) {
        fprintf(stderr, "Warning: sbe-sample-app is using a deprecated schema\n");
    }
    const auto status = decoder.status();
    auto& rate_limits = decoder.rateLimits();
    std::vector<WebSocketMetadata::RateLimit> limits;
    limits.reserve(rate_limits.count());
    rate_limits.forEach([&](const auto& rate_limit) {
        const auto rate_limit_type = rate_limit.rateLimitType();
        const auto interval = rate_limit.interval();
        const auto interval_num = rate_limit.intervalNum();
        const auto limit = rate_limit.rateLimit();
        const auto count = rate_limit.current();
        limits.push_back(
            WebSocketMetadata::RateLimit{rate_limit_type, interval, interval_num, limit, count});
    });
    auto id = decoder.getIdAsString();
    const auto result_length = decoder.resultLength();
    auto result = std::span<char>(const_cast<char*>(decoder.result()), result_length);
    return WebSocketMetadata{status, std::move(limits), std::move(id), std::move(result)};
}

int main() {
    auto storage = read_payload(STDIN_FILENO);
    auto payload = std::span<char>{storage};
    MessageHeader message_header{payload.data(), payload.size()};

    // A separate "ErrorResponse" message is returned for errors and its format
    // is expected to be backwards compatible across all schema IDs.
    auto template_id = message_header.templateId();
    if (template_id == ErrorResponse::sbeTemplateId()) {
        const auto result = decode_error_response(payload, message_header);
        print_json(result);
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

    std::optional<WebSocketMetadata> websocket_meta;
    if (template_id == WebSocketResponse::sbeTemplateId()) {
        websocket_meta = decode_websocket_response(payload, message_header);
        payload = websocket_meta->result;
        message_header = MessageHeader{payload.data(), payload.size()};
        template_id = message_header.templateId();

        if (template_id == ErrorResponse::sbeTemplateId()) {
            const auto result = decode_error_response(payload, message_header);
            print_json(websocket_meta, result);
            return 1;
        }
    }

    if (template_id == AccountResponse::sbeTemplateId()) {
        const auto result = decode_account(payload, message_header);
        print_json(websocket_meta, result);
    } else if (template_id == ExchangeInfoResponse::sbeTemplateId()) {
        const auto result = decode_exchange_info(payload, message_header);
        print_json(websocket_meta, result);
    } else if (template_id == NewOrderResultResponse::sbeTemplateId()) {
        const auto result = decode_post_order(payload, message_header);
        print_json(websocket_meta, result);
    } else if (template_id == OrderResponse::sbeTemplateId()) {
        const auto result = decode_get_order(payload, message_header);
        print_json(websocket_meta, result);
    } else {
        fprintf(stderr, "Unexpected template ID %d\n", template_id);
        return 1;
    }

    return 0;
}
