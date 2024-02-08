#ifndef _SBE_APP_JSON_H_
#define _SBE_APP_JSON_H_

#include <unistd.h>
#include <array>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <optional>
#include <variant>
#include <vector>

#include "account.h"
#include "error.h"
#include "exchange_info.h"
#include "post_order.h"
#include "web_socket_metadata.h"

enum class FieldPos {
    Default,
    Last,
};

void print_str(const char* const key,
               const char* const value,
               const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":\"%s\"%s", key, value, pos == FieldPos::Default ? "," : "");
}

template <typename T>
void print_json_object(const char* key, const T& object, const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":", key);
    print_json(object);
    if (pos != FieldPos::Last) {
        printf(",");
    }
}

const char* bool_str(const bool b) {
    if (b) {
        return "true";
    } else {
        return "false";
    }
}

void print_bool(const char* const key, const bool value, const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":%s%s", key, bool_str(value), pos == FieldPos::Default ? "," : "");
}

void print_int(const char* const key, const int value, const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":%d%s", key, value, pos == FieldPos::Default ? "," : "");
}

void print_long(const char* const key, const long value, const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":%ld%s", key, value, pos == FieldPos::Default ? "," : "");
}

void print_json(const Error& error) {
    printf("{");
    print_int("code", error.code);
    if (error.server_time) {
        print_long("serverTime", *error.server_time);
    }
    if (error.retry_after) {
        print_long("retryAfter", *error.retry_after);
    }
    print_str("msg", error.msg.c_str(), FieldPos::Last);
    printf("}");
}

void print_decimal(const char* const key,
                   const Decimal& val,
                   const FieldPos pos = FieldPos::Default) {
    if (val.exponent >= 0) {
        auto value = std::to_string(val.mantissa);
        value.append(val.exponent, '0');
        print_str(key, value.data(), pos);
        return;
    }
    auto buffer = std::array<char, 64>{};
    const auto sign = (val.mantissa < 0) ? "-" : "";
    const auto mantissa = (val.mantissa < 0) ? -val.mantissa : val.mantissa;
    const auto exponent = -val.exponent;
    using mantissa_type = decltype(mantissa);
    auto divisor = mantissa_type{1};
    using exponent_type = decltype(exponent);
    for (auto i = exponent_type{0}; i < exponent; ++i) {
        divisor *= 10;
    }
    const auto whole_part = mantissa / divisor;
    const auto frac_part = mantissa % divisor;
    if (std::snprintf(buffer.data(), buffer.size(), "%s%ld.%0*ld", sign, whole_part, exponent,
                      frac_part) < 0) {
        fprintf(stderr, "Unexpected error printing decimal\n");
        exit(1);
    }
    print_str(key, buffer.data(), pos);
}

void print_json(const char* const key,
                const CommissionRates& val,
                const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":{", key);
    print_decimal("maker", val.commission_rate_maker);
    print_decimal("taker", val.commission_rate_taker);
    print_decimal("buyer", val.commission_rate_buyer);
    print_decimal("seller", val.commission_rate_seller, FieldPos::Last);
    printf("}%s", pos == FieldPos::Default ? "," : "");
}

void print_json(const RateLimit& val) {
    printf("{");
    print_str("rateLimitType", RateLimitType::c_str(val.rate_limit_type));
    print_str("interval", RateLimitInterval::c_str(val.interval));
    print_int("intervalNum", val.interval_num);
    print_long("limit", val.rate_limit, FieldPos::Last);
    printf("}");
}

void print_json(const ExchangeMaxNumOrders& val) {
    print_long("maxNumOrders", val.max_num_orders, FieldPos::Last);
}

void print_json(const ExchangeMaxNumAlgoOrders& val) {
    print_long("maxNumAlgoOrders", val.max_num_algo_orders, FieldPos::Last);
}

void print_json(const ExchangeMaxNumIcebergOrders& val) {
    print_long("maxNumIcebergOrders", val.max_num_iceberg_orders, FieldPos::Last);
}

void print_json(const SymbolPriceFilter& val) {
    print_decimal("minPrice", val.min_price);
    print_decimal("maxPrice", val.max_price);
    print_decimal("tickSize", val.tick_size, FieldPos::Last);
}

void print_json(const SymbolPercentPriceFilter& val) {
    print_decimal("multiplierUp", val.multiplier_up);
    print_decimal("multiplierDown", val.multiplier_down);
    print_int("avgPriceMins", val.avg_price_mins, FieldPos::Last);
}

void print_json(const SymbolPercentPriceBySideFilter& val) {
    print_decimal("bidMultiplierUp", val.bid_multiplier_up);
    print_decimal("bidMultiplierDown", val.bid_multiplier_down);
    print_decimal("askMultiplierUp", val.ask_multiplier_up);
    print_decimal("askMultiplierDown", val.ask_multiplier_down);
    print_int("avgPriceMins", val.avg_price_mins, FieldPos::Last);
}

void print_json(const SymbolLotSizeFilter& val) {
    print_decimal("minQty", val.min_qty);
    print_decimal("maxQty", val.max_qty);
    print_decimal("stepSize", val.step_size, FieldPos::Last);
}

void print_json(const SymbolMinNotionalFilter& val) {
    print_decimal("minNotional", val.min_notional);
    print_bool("applyToMarket", val.apply_to_market);
    print_int("avgPriceMins", val.avg_price_mins, FieldPos::Last);
}

void print_json(const SymbolNotionalFilter& val) {
    print_decimal("minNotional", val.min_notional);
    print_bool("applyMinToMarket", val.apply_min_to_market);
    print_decimal("maxNotional", val.max_notional);
    print_bool("applyMaxToMarket", val.apply_max_to_market);
    print_int("avgPriceMins", val.avg_price_mins, FieldPos::Last);
}

void print_json(const SymbolIcebergPartsFilter& val) {
    print_long("limit", val.filter_limit, FieldPos::Last);
}

void print_json(const SymbolMarketLotSizeFilter& val) {
    print_decimal("minQty", val.min_qty);
    print_decimal("maxQty", val.max_qty);
    print_decimal("stepSize", val.step_size, FieldPos::Last);
}

void print_json(const SymbolMaxNumOrdersFilter& val) {
    print_long("maxNumOrders", val.max_num_orders, FieldPos::Last);
}

void print_json(const SymbolMaxNumAlgoOrdersFilter& val) {
    print_long("maxNumAlgoOrders", val.max_num_algo_orders, FieldPos::Last);
}

void print_json(const SymbolMaxNumIcebergOrdersFilter& val) {
    print_long("maxNumIcebergOrders", val.max_num_iceberg_orders, FieldPos::Last);
}

void print_json(const SymbolMaxPositionFilter& val) {
    print_decimal("maxPosition", val.max_position, FieldPos::Last);
}

void print_json(const SymbolTrailingDeltaFilter& val) {
    print_long("minTrailingAboveDelta", val.min_trailing_above_delta);
    print_long("maxTrailingAboveDelta", val.max_trailing_above_delta);
    print_long("minTrailingBelowDelta", val.min_trailing_below_delta);
    print_long("maxTrailingBelowDelta", val.max_trailing_below_delta, FieldPos::Last);
}

void print_json(const SymbolTPlusSellFilter& val) {
    int64_t end_time = val.end_time ? *val.end_time : -1;
    print_long("endTime", end_time, FieldPos::Last);
}

void print_json(const SymbolFilter& val) {
    printf("{");
    printf("\"filterType\": \"%s\",", FilterType::c_str(val.filter_type));
    std::visit([](auto&& filter) { print_json(filter); }, val.data);
    printf("}");
}

void print_str_vec(const char* const key,
                   const std::vector<std::string>& str_vec,
                   const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":[", key);
    for (const auto& str : str_vec) {
        printf("\"%s\"", str.c_str());
        if (&str != &str_vec.back()) {
            printf(",");
        }
    }
    printf("]%s", pos == FieldPos::Default ? "," : "");
}

template <typename T>
void print_json_vec(const char* const key,
                    const std::vector<T>& vec,
                    const FieldPos pos = FieldPos::Default) {
    printf("\"%s\":[", key);
    for (const auto& item : vec) {
        print_json(item);
        if (&item != &vec.back()) {
            printf(",");
        }
    }
    printf("]%s", pos == FieldPos::Default ? "," : "");
}

void print_json(const OrderTypes& val, const FieldPos pos = FieldPos::Default) {
    std::vector<std::string> order_types;
    if (val.contains(OrderTypes::Limit)) {
        order_types.push_back("Limit");
    }
    if (val.contains(OrderTypes::LimitMaker)) {
        order_types.push_back("LimitMaker");
    }
    if (val.contains(OrderTypes::Market)) {
        order_types.push_back("Market");
    }
    if (val.contains(OrderTypes::StopLoss)) {
        order_types.push_back("StopLoss");
    }
    if (val.contains(OrderTypes::StopLossLimit)) {
        order_types.push_back("StopLossLimit");
    }
    if (val.contains(OrderTypes::TakeProfit)) {
        order_types.push_back("TakeProfit");
    }
    if (val.contains(OrderTypes::TakeProfitLimit)) {
        order_types.push_back("TakeProfitLimit");
    }
    print_str_vec("orderTypes", order_types, pos);
}

void print_json(const SelfTradePreventionModes& val, const FieldPos pos = FieldPos::Default) {
    std::vector<std::string> allowed_modes;
    if (val.contains(SelfTradePreventionModes::None)) {
        allowed_modes.push_back("None");
    }
    if (val.contains(SelfTradePreventionModes::ExpireTaker)) {
        allowed_modes.push_back("ExpireTaker");
    }
    if (val.contains(SelfTradePreventionModes::ExpireMaker)) {
        allowed_modes.push_back("ExpireMaker");
    }
    if (val.contains(SelfTradePreventionModes::ExpireBoth)) {
        allowed_modes.push_back("ExpireBoth");
    }
    print_str_vec("allowedSelfTradePreventionModes", allowed_modes, pos);
}

void print_json(const SymbolInfo& symbol) {
    printf("{");
    print_str("symbol", symbol.symbol.c_str());
    print_str("status", SymbolStatus::c_str(symbol.status));
    print_str("baseAsset", symbol.base_asset.c_str());
    print_int("baseAssetPrecision", symbol.base_asset_precision);
    print_str("quoteAsset", symbol.quote_asset.c_str());
    print_int("quoteAssetPrecision", symbol.quote_asset_precision);
    print_int("baseCommissionPrecision", symbol.base_commission_precision);
    print_int("quoteCommissionPrecision", symbol.quote_commission_precision);
    print_json(symbol.order_types);
    print_bool("icebergAllowed", symbol.iceberg_allowed);
    print_bool("ocoAllowed", symbol.oco_allowed);
    print_bool("quoteOrderQtyMarketAllowed", symbol.quote_order_qty_market_allowed);
    print_bool("allowTrailingStop", symbol.allow_trailing_stop);
    print_bool("cancelReplaceAllowed", symbol.cancel_replace_allowed);
    print_bool("isSpotTradingAllowed", symbol.is_spot_trading_allowed);
    print_bool("isMarginTradingAllowed", symbol.is_margin_trading_allowed);
    print_json_vec("filters", symbol.filters);
    print_str_vec("permissions", symbol.permissions);
    print_str("defaultSelfTradePreventionMode",
              SelfTradePreventionMode::c_str(symbol.default_self_trade_prevention_mode));
    print_json(symbol.allowed_self_trade_prevention_modes, FieldPos::Last);
    printf("}");
}

void print_json(const Sor& sor) {
    printf("{");
    print_str("baseAsset", sor.base_asset.c_str());
    print_str_vec("symbols", sor.symbols, FieldPos::Last);
    printf("}");
}

void print_json(const Balances& balance) {
    printf("{");
    print_str("asset", balance.asset.c_str());
    print_decimal("free", balance.free);
    print_decimal("locked", balance.locked, FieldPos::Last);
    printf("}");
}

void print_json(const Account& account) {
    printf("{");
    print_json("commissionRates", account.commission_rates);
    print_bool("canTrade", account.can_trade);
    print_bool("canWithdraw", account.can_withdraw);
    print_bool("canDeposit", account.can_deposit);
    print_bool("brokered", account.brokered);
    print_bool("requireSelfTradePrevention", account.require_self_trade_prevention);
    print_bool("preventSor", account.prevent_sor);
    print_long("updateTime", account.update_time);
    print_str("accountType", AccountType::c_str(account.account_type));
    if (account.trade_group_id) {
        print_int("tradeGroupId", *account.trade_group_id);
    }
    print_json_vec("balances", account.balances);
    print_str_vec("permissions", account.permissions);
    print_str_vec("reduceOnlyAssets", account.reduce_only_assets);
    print_long("uid", account.uid, FieldPos::Last);
    printf("}");
}

void print_json(const ExchangeInfo& val) {
    printf("{");
    print_json_vec("rateLimits", val.rate_limits);
    printf("\"exchangeFilters\":[");
    for (const auto& filter : val.exchange_filters) {
        printf("{");
        const auto filter_type = filter.filter_type;
        printf("\"filterType\": \"%s\",", FilterType::c_str(filter_type));
        std::visit([](auto&& filter) { print_json(filter); }, filter.data);
        printf("}");
        if (&filter != &val.exchange_filters.back()) {
            printf(",");
        }
    }
    printf("],");
    print_json_vec("symbols", val.symbols);
    print_json_vec("sors", val.sors, FieldPos::Last);
    printf("}");
}

void print_json(const NewOrder& new_order) {
    printf("{");
    print_str("symbol", new_order.symbol.c_str());
    print_long("orderId", new_order.order_id);
    if (new_order.order_list_id) {
        print_long("orderListId", *new_order.order_list_id);
    } else {
        print_int("orderListId", -1);
    }
    print_str("clientOrderId", new_order.client_order_id.c_str());
    print_long("transactTime", new_order.transaction_time);
    print_decimal("price", new_order.price);
    print_decimal("origQty", new_order.orig_qty);
    print_decimal("executedQty", new_order.executed_qty);
    print_decimal("cummulativeQuoteQty", new_order.cummulative_quote_qty);
    print_str("status", OrderStatus::c_str(new_order.status));
    print_str("timeInForce", TimeInForce::c_str(new_order.time_in_force));
    print_str("type", OrderType::c_str(new_order.order_type));
    print_str("side", OrderSide::c_str(new_order.side));
    if (new_order.working_time) {
        print_long("workingTime", *new_order.working_time);
    }
    if (new_order.stop_price) {
        print_decimal("stopPrice", *new_order.stop_price);
    }
    if (new_order.trailing_delta) {
        print_long("trailingDelta", *new_order.trailing_delta);
    }
    if (new_order.trailing_time) {
        print_long("trailingTime", *new_order.trailing_time);
    }
    if (new_order.iceberg_qty) {
        print_long("icebergQty", *new_order.iceberg_qty);
    }
    if (new_order.strategy_id) {
        print_long("strategyId", *new_order.strategy_id);
    }
    if (new_order.strategy_type) {
        print_long("strategyType", *new_order.strategy_type);
    }
    if (new_order.order_capacity != OrderCapacity::Value::NULL_VALUE) {
        print_str("orderCapacity", OrderCapacity::c_str(*new_order.order_capacity));
    }
    if (new_order.working_floor != Floor::Value::NULL_VALUE) {
        print_str("workingFloor", Floor::c_str(*new_order.working_floor));
    }
    if (new_order.trade_group_id) {
        print_long("tradeGroupId", *new_order.trade_group_id);
    }
    if (new_order.prevented_quantity) {
        print_decimal("preventedQuantity", *new_order.prevented_quantity);
    }
    if (new_order.used_sor) {
        print_bool("usedSor", *new_order.used_sor);
    }
    print_str("selfTradePreventionMode",
              SelfTradePreventionMode::c_str(new_order.self_trade_prevention_mode), FieldPos::Last);
    printf("}");
}

void print_json(const GetOrder& get_order) {
    printf("{");
    print_str("symbol", get_order.symbol.c_str());
    print_long("orderId", get_order.order_id);
    if (get_order.order_list_id) {
        print_long("orderListId", *get_order.order_list_id);
    } else {
        print_int("orderListId", -1);
    }
    print_str("clientOrderId", get_order.client_order_id.c_str());
    print_decimal("price", get_order.price);
    print_decimal("origQty", get_order.orig_qty);
    print_decimal("executedQty", get_order.executed_qty);
    print_decimal("cummulativeQuoteQty", get_order.cummulative_quote_qty);
    print_str("status", OrderStatus::c_str(get_order.status));
    print_str("timeInForce", TimeInForce::c_str(get_order.time_in_force));
    print_str("type", OrderType::c_str(get_order.order_type));
    print_str("side", OrderSide::c_str(get_order.side));
    if (get_order.stop_price) {
        print_decimal("stopPrice", *get_order.stop_price);
    }
    if (get_order.trailing_delta) {
        print_long("trailingDelta", *get_order.trailing_delta);
    }
    if (get_order.trailing_time) {
        print_long("trailingTime", *get_order.trailing_time);
    }
    if (get_order.iceberg_qty) {
        print_decimal("icebergQty", *get_order.iceberg_qty);
    }
    print_long("time", get_order.time);
    print_long("updateTime", get_order.update_time);
    print_bool("isWorking", get_order.is_working);
    if (get_order.working_time) {
        print_long("workingTime", *get_order.working_time);
    }
    print_decimal("origQuoteOrderQty", get_order.orig_quote_order_qty);
    if (get_order.strategy_id) {
        print_long("strategyId", *get_order.strategy_id);
    }
    if (get_order.strategy_type) {
        print_int("strategyType", *get_order.strategy_type);
    }
    if (get_order.order_capacity != OrderCapacity::Value::NULL_VALUE) {
        print_str("orderCapacity", OrderCapacity::c_str(*get_order.order_capacity));
    }
    if (get_order.working_floor != Floor::Value::NULL_VALUE) {
        print_str("workingFloor", Floor::c_str(*get_order.working_floor));
    }
    print_str("selfTradePreventionMode",
              SelfTradePreventionMode::c_str(get_order.self_trade_prevention_mode));
    if (get_order.prevented_match_id) {
        print_long("preventedMatchId", *get_order.prevented_match_id);
    }
    if (get_order.prevented_quantity) {
        print_decimal("preventedQuantity", *get_order.prevented_quantity);
    }
    if (get_order.used_sor) {
        print_bool("usedSor", *get_order.used_sor, FieldPos::Last);
    }
    printf("}");
}

void print_json(const WebSocketMetadata::RateLimit& val) {
    printf("{");
    print_str("rateLimitType", RateLimitType::c_str(val.rate_limit_type));
    print_str("interval", RateLimitInterval::c_str(val.interval));
    print_int("intervalNum", val.interval_num);
    print_long("limit", val.rate_limit);
    print_long("count", val.current, FieldPos::Last);
    printf("}");
}

template <typename T>
void print_json(const std::optional<WebSocketMetadata>& websocket_meta, const T& result) {
    if (!websocket_meta) {
        print_json(result);
        return;
    }
    printf("{");
    print_long("status", websocket_meta->status);
    print_json_vec("rateLimits", websocket_meta->rate_limits);
    print_str("id", websocket_meta->id.c_str());
    print_json_object("result", result, FieldPos::Last);
    printf("}");
}

#endif
