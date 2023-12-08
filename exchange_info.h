#ifndef _SBE_APP_EXCHANGE_INFO_H_
#define _SBE_APP_EXCHANGE_INFO_H_

#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <optional>
#include <variant>
#include <vector>

#include "spot_sbe/ExchangeMaxNumAlgoOrdersFilter.h"
#include "spot_sbe/ExchangeMaxNumIcebergOrdersFilter.h"
#include "spot_sbe/ExchangeMaxNumOrdersFilter.h"
#include "spot_sbe/FilterType.h"
#include "spot_sbe/IcebergPartsFilter.h"
#include "spot_sbe/LotSizeFilter.h"
#include "spot_sbe/MarketLotSizeFilter.h"
#include "spot_sbe/MaxNumAlgoOrdersFilter.h"
#include "spot_sbe/MaxNumIcebergOrdersFilter.h"
#include "spot_sbe/MaxNumOrdersFilter.h"
#include "spot_sbe/MaxPositionFilter.h"
#include "spot_sbe/MessageHeader.h"
#include "spot_sbe/MinNotionalFilter.h"
#include "spot_sbe/NotionalFilter.h"
#include "spot_sbe/OrderType.h"
#include "spot_sbe/PercentPriceBySideFilter.h"
#include "spot_sbe/PercentPriceFilter.h"
#include "spot_sbe/PriceFilter.h"
#include "spot_sbe/RateLimitInterval.h"
#include "spot_sbe/RateLimitType.h"
#include "spot_sbe/SelfTradePreventionMode.h"
#include "spot_sbe/SymbolStatus.h"
#include "spot_sbe/TPlusSellFilter.h"
#include "spot_sbe/TrailingDeltaFilter.h"
#include "util.h"

using spot_sbe::ExchangeMaxNumAlgoOrdersFilter;
using spot_sbe::ExchangeMaxNumIcebergOrdersFilter;
using spot_sbe::ExchangeMaxNumOrdersFilter;
using spot_sbe::FilterType;
using spot_sbe::IcebergPartsFilter;
using spot_sbe::LotSizeFilter;
using spot_sbe::MarketLotSizeFilter;
using spot_sbe::MaxNumAlgoOrdersFilter;
using spot_sbe::MaxNumIcebergOrdersFilter;
using spot_sbe::MaxNumOrdersFilter;
using spot_sbe::MaxPositionFilter;
using spot_sbe::MessageHeader;
using spot_sbe::MinNotionalFilter;
using spot_sbe::NotionalFilter;
using spot_sbe::PercentPriceBySideFilter;
using spot_sbe::PercentPriceFilter;
using spot_sbe::PriceFilter;
using spot_sbe::RateLimitInterval;
using spot_sbe::RateLimitType;
using spot_sbe::SelfTradePreventionMode;
using spot_sbe::SymbolStatus;
using spot_sbe::TPlusSellFilter;
using spot_sbe::TrailingDeltaFilter;

struct Decimal {
    int64_t mantissa;
    int8_t exponent;
};

struct RateLimit {
    RateLimitType::Value rate_limit_type;
    RateLimitInterval::Value interval;
    uint8_t interval_num;
    int64_t rate_limit;
};

struct ExchangeMaxNumOrders {
    int64_t max_num_orders;

    explicit ExchangeMaxNumOrders(const int64_t value) : max_num_orders{value} {}
};

struct ExchangeMaxNumAlgoOrders {
    int64_t max_num_algo_orders;

    explicit ExchangeMaxNumAlgoOrders(const int64_t value) : max_num_algo_orders{value} {}
};

struct ExchangeMaxNumIcebergOrders {
    int64_t max_num_iceberg_orders;

    explicit ExchangeMaxNumIcebergOrders(const int64_t value) : max_num_iceberg_orders{value} {}
};

typedef std::variant<ExchangeMaxNumOrders, ExchangeMaxNumAlgoOrders, ExchangeMaxNumIcebergOrders>
    ExchangeFilterData;

struct ExchangeFilter {
    FilterType::Value filter_type;
    ExchangeFilterData data;
};

ExchangeFilter make_exchange_filter(const MessageHeader& header,
                                    char* const filter_data,
                                    const size_t filter_size) {
    switch (header.templateId()) {
        case ExchangeMaxNumOrdersFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<ExchangeMaxNumOrdersFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return ExchangeFilter{filter_type, ExchangeMaxNumOrders{msg.maxNumOrders()}};
        }
        case ExchangeMaxNumAlgoOrdersFilter::sbeTemplateId(): {
            const auto msg = message_from_header<ExchangeMaxNumAlgoOrdersFilter>(
                filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return ExchangeFilter{filter_type, ExchangeMaxNumAlgoOrders{msg.maxNumAlgoOrders()}};
        }
        case ExchangeMaxNumIcebergOrdersFilter::sbeTemplateId(): {
            const auto msg = message_from_header<ExchangeMaxNumIcebergOrdersFilter>(
                filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return ExchangeFilter{filter_type,
                                  ExchangeMaxNumIcebergOrders{msg.maxNumIcebergOrders()}};
        }
        default: {
            fprintf(stderr, "Unexpected template ID %d\n", header.templateId());
            exit(1);
        }
    }
}

struct SymbolPriceFilter {
    Decimal min_price;
    Decimal max_price;
    Decimal tick_size;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "priceExponent" field as a
    // parameter.
    SymbolPriceFilter(const PriceFilter& decoder, const int8_t price_exponent)
        : min_price{decoder.minPrice(), price_exponent},
          max_price{decoder.maxPrice(), price_exponent},
          tick_size{decoder.tickSize(), price_exponent} {}
};

struct SymbolPercentPriceFilter {
    Decimal multiplier_up;
    Decimal multiplier_down;
    int32_t avg_price_mins;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "multiplierExponent" field as a
    // parameter.
    SymbolPercentPriceFilter(const PercentPriceFilter& decoder, const int8_t multiplier_exponent)
        : multiplier_up{decoder.multiplierUp(), multiplier_exponent},
          multiplier_down{decoder.multiplierDown(), multiplier_exponent},
          avg_price_mins{decoder.avgPriceMins()} {}
};

struct SymbolPercentPriceBySideFilter {
    Decimal bid_multiplier_up;
    Decimal bid_multiplier_down;
    Decimal ask_multiplier_up;
    Decimal ask_multiplier_down;
    int32_t avg_price_mins;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "multiplierExponent" field as a
    // parameter.
    SymbolPercentPriceBySideFilter(const PercentPriceBySideFilter& decoder,
                                   const int8_t multiplier_exponent)
        : bid_multiplier_up{decoder.bidMultiplierUp(), multiplier_exponent},
          bid_multiplier_down{decoder.bidMultiplierDown(), multiplier_exponent},
          ask_multiplier_up{decoder.askMultiplierUp(), multiplier_exponent},
          ask_multiplier_down{decoder.askMultiplierDown(), multiplier_exponent},
          avg_price_mins{decoder.avgPriceMins()} {}
};

struct SymbolLotSizeFilter {
    Decimal min_qty;
    Decimal max_qty;
    Decimal step_size;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "qtyExponent" field as a parameter.
    SymbolLotSizeFilter(const LotSizeFilter& decoder, const int8_t qty_exponent)
        : min_qty{decoder.minQty(), qty_exponent},
          max_qty{decoder.maxQty(), qty_exponent},
          step_size{decoder.stepSize(), qty_exponent} {}
};

struct SymbolMinNotionalFilter {
    Decimal min_notional;
    bool apply_to_market;
    int32_t avg_price_mins;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "priceExponent" field as a
    // parameter.
    SymbolMinNotionalFilter(const MinNotionalFilter& decoder, const int8_t price_exponent)
        : min_notional{decoder.minNotional(), price_exponent},
          apply_to_market{decoder.applyToMarket() != 0},
          avg_price_mins{decoder.avgPriceMins()} {}
};

struct SymbolNotionalFilter {
    Decimal min_notional;
    bool apply_min_to_market;
    Decimal max_notional;
    bool apply_max_to_market;
    int32_t avg_price_mins;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "priceExponent" field as a
    // parameter.
    SymbolNotionalFilter(const NotionalFilter& decoder, const int8_t price_exponent)
        : min_notional{decoder.minNotional(), price_exponent},
          apply_min_to_market{decoder.applyMinToMarket() != 0},
          max_notional{decoder.maxNotional(), price_exponent},
          apply_max_to_market{decoder.applyMaxToMarket() != 0},
          avg_price_mins{decoder.avgPriceMins()} {}
};

struct SymbolIcebergPartsFilter {
    int64_t filter_limit;

    SymbolIcebergPartsFilter(const IcebergPartsFilter& decoder)
        : filter_limit{decoder.filterLimit()} {}
};

struct SymbolMarketLotSizeFilter {
    Decimal min_qty;
    Decimal max_qty;
    Decimal step_size;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "qtyExponent" field as a
    // parameter.
    SymbolMarketLotSizeFilter(const MarketLotSizeFilter& decoder, const int8_t qty_exponent)
        : min_qty{decoder.minQty(), qty_exponent},
          max_qty{decoder.maxQty(), qty_exponent},
          step_size{decoder.stepSize(), qty_exponent} {}
};

struct SymbolMaxNumOrdersFilter {
    int64_t max_num_orders;

    SymbolMaxNumOrdersFilter(const int64_t max_num_orders) : max_num_orders{max_num_orders} {}

    SymbolMaxNumOrdersFilter(const MaxNumOrdersFilter& decoder)
        : max_num_orders{decoder.maxNumOrders()} {}
};

struct SymbolMaxNumAlgoOrdersFilter {
    int64_t max_num_algo_orders;

    SymbolMaxNumAlgoOrdersFilter(const MaxNumAlgoOrdersFilter& decoder)
        : max_num_algo_orders{decoder.maxNumAlgoOrders()} {}
};

struct SymbolMaxNumIcebergOrdersFilter {
    int64_t max_num_iceberg_orders;

    SymbolMaxNumIcebergOrdersFilter(const MaxNumIcebergOrdersFilter& decoder)
        : max_num_iceberg_orders{decoder.maxNumIcebergOrders()} {}
};

struct SymbolMaxPositionFilter {
    Decimal max_position;

    // It is best practice to decode fields one time in the order that they
    // appear in the XML schema so take the "qtyExponent" field as a
    // parameter.
    SymbolMaxPositionFilter(const MaxPositionFilter& decoder, const int8_t qty_exponent)
        : max_position{decoder.maxPosition(), qty_exponent} {}
};

struct SymbolTrailingDeltaFilter {
    int64_t min_trailing_above_delta;
    int64_t max_trailing_above_delta;
    int64_t min_trailing_below_delta;
    int64_t max_trailing_below_delta;

    SymbolTrailingDeltaFilter(const TrailingDeltaFilter& decoder)
        : min_trailing_above_delta{decoder.minTrailingAboveDelta()},
          max_trailing_above_delta{decoder.maxTrailingAboveDelta()},
          min_trailing_below_delta{decoder.minTrailingBelowDelta()},
          max_trailing_below_delta{decoder.maxTrailingBelowDelta()} {}
};

struct SymbolTPlusSellFilter {
    std::optional<int64_t> end_time;

    SymbolTPlusSellFilter(const TPlusSellFilter& decoder) : end_time{decoder.endTime()} {
        if (end_time.value() == decoder.endTimeNullValue()) {
            end_time.reset();
        }
    }
};

typedef std::variant<SymbolPriceFilter,
                     SymbolPercentPriceFilter,
                     SymbolPercentPriceBySideFilter,
                     SymbolLotSizeFilter,
                     SymbolMinNotionalFilter,
                     SymbolNotionalFilter,
                     SymbolIcebergPartsFilter,
                     SymbolMarketLotSizeFilter,
                     SymbolMaxNumOrdersFilter,
                     SymbolMaxNumAlgoOrdersFilter,
                     SymbolMaxNumIcebergOrdersFilter,
                     SymbolMaxPositionFilter,
                     SymbolTrailingDeltaFilter,
                     SymbolTPlusSellFilter>
    SymbolFilterData;

struct SymbolFilter {
    FilterType::Value filter_type;
    SymbolFilterData data;
};

SymbolFilter make_symbol_filter(const MessageHeader& header,
                                char* const filter_data,
                                const size_t filter_size) {
    switch (header.templateId()) {
        case PriceFilter::sbeTemplateId(): {
            const auto msg = message_from_header<PriceFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolPriceFilter{msg, msg.priceExponent()}};
        }
        case PercentPriceFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<PercentPriceFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type,
                                SymbolPercentPriceFilter{msg, msg.multiplierExponent()}};
        }
        case PercentPriceBySideFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<PercentPriceBySideFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type,
                                SymbolPercentPriceBySideFilter{msg, msg.multiplierExponent()}};
        }
        case LotSizeFilter::sbeTemplateId(): {
            const auto msg = message_from_header<LotSizeFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolLotSizeFilter{msg, msg.qtyExponent()}};
        }
        case MinNotionalFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<MinNotionalFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolMinNotionalFilter{msg, msg.priceExponent()}};
        }
        case NotionalFilter::sbeTemplateId(): {
            const auto msg = message_from_header<NotionalFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolNotionalFilter{msg, msg.priceExponent()}};
        }
        case IcebergPartsFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<IcebergPartsFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolIcebergPartsFilter{msg}};
        }
        case MarketLotSizeFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<MarketLotSizeFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolMarketLotSizeFilter{msg, msg.qtyExponent()}};
        }
        case MaxNumOrdersFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<MaxNumOrdersFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolMaxNumOrdersFilter{msg}};
        }
        case MaxNumAlgoOrdersFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<MaxNumAlgoOrdersFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolMaxNumAlgoOrdersFilter{msg}};
        }
        case MaxNumIcebergOrdersFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<MaxNumIcebergOrdersFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, MaxNumIcebergOrdersFilter{msg}};
        }
        case MaxPositionFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<MaxPositionFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolMaxPositionFilter{msg, msg.qtyExponent()}};
        }
        case TrailingDeltaFilter::sbeTemplateId(): {
            const auto msg =
                message_from_header<TrailingDeltaFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolTrailingDeltaFilter{msg}};
        }
        case TPlusSellFilter::sbeTemplateId(): {
            const auto msg = message_from_header<TPlusSellFilter>(filter_data, filter_size, header);
            const auto filter_type = msg.filterType();
            return SymbolFilter{filter_type, SymbolTPlusSellFilter{msg}};
        }
        default: {
            fprintf(stderr, "Unexpected template ID %d\n", header.templateId());
            exit(1);
        }
    }
}

struct OrderTypes {
    uint32_t value;

    enum Flags {
        Market = 1,
        Limit = 2,
        StopLoss = 4,
        StopLossLimit = 8,
        TakeProfit = 16,
        TakeProfitLimit = 32,
        LimitMaker = 64,
    };

    explicit OrderTypes(const spot_sbe::OrderTypes& order_types) : value{0} {
        if (order_types.market()) {
            value |= Flags::Market;
        }
        if (order_types.limit()) {
            value |= Flags::Limit;
        }
        if (order_types.stopLoss()) {
            value |= Flags::StopLoss;
        }
        if (order_types.stopLossLimit()) {
            value |= Flags::StopLossLimit;
        }
        if (order_types.takeProfit()) {
            value |= Flags::TakeProfit;
        }
        if (order_types.takeProfitLimit()) {
            value |= Flags::TakeProfitLimit;
        }
        if (order_types.limitMaker()) {
            value |= Flags::LimitMaker;
        }
    }

    bool contains(const OrderTypes::Flags flag) const { return value & flag; }
};

struct SelfTradePreventionModes {
    uint32_t value;

    enum Flags {
        None = 1,
        ExpireTaker = 2,
        ExpireMaker = 4,
        ExpireBoth = 8,
    };

    explicit SelfTradePreventionModes(const spot_sbe::AllowedSelfTradePreventionModes& modes)
        : value{0} {
        if (modes.none()) {
            value |= Flags::None;
        }
        if (modes.expireTaker()) {
            value |= Flags::ExpireTaker;
        }
        if (modes.expireMaker()) {
            value |= Flags::ExpireMaker;
        }
        if (modes.expireBoth()) {
            value |= Flags::ExpireBoth;
        }
    }

    bool contains(const SelfTradePreventionModes::Flags flag) const { return value & flag; }
};

struct SymbolInfo {
    SymbolStatus::Value status;
    uint8_t base_asset_precision;
    uint8_t quote_asset_precision;
    uint8_t base_commission_precision;
    uint8_t quote_commission_precision;
    OrderTypes order_types;
    bool iceberg_allowed;
    bool oco_allowed;
    bool quote_order_qty_market_allowed;
    bool allow_trailing_stop;
    bool cancel_replace_allowed;
    bool is_spot_trading_allowed;
    bool is_margin_trading_allowed;
    SelfTradePreventionMode::Value default_self_trade_prevention_mode;
    SelfTradePreventionModes allowed_self_trade_prevention_modes;
    std::vector<SymbolFilter> filters;
    std::vector<std::string> permissions;
    std::string symbol;
    std::string base_asset;
    std::string quote_asset;
};

struct Sor {
    std::vector<std::string> symbols;
    std::string base_asset;
};

struct ExchangeInfo {
    std::vector<RateLimit> rate_limits;
    std::vector<ExchangeFilter> exchange_filters;
    std::vector<SymbolInfo> symbols;
    std::vector<Sor> sors;
};

#endif
