#ifndef _SBE_APP_GET_ORDER_H_
#define _SBE_APP_GET_ORDER_H_

#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <optional>
#include <variant>
#include <vector>

#include "decimal.h"
#include "spot_sbe/Floor.h"
#include "spot_sbe/MatchType.h"
#include "spot_sbe/OrderCapacity.h"
#include "spot_sbe/OrderSide.h"
#include "spot_sbe/OrderStatus.h"
#include "spot_sbe/OrderType.h"
#include "spot_sbe/SelfTradePreventionMode.h"
#include "spot_sbe/TimeInForce.h"
#include "util.h"

using spot_sbe::Floor;
using spot_sbe::MatchType;
using spot_sbe::OrderCapacity;
using spot_sbe::OrderSide;
using spot_sbe::OrderStatus;
using spot_sbe::OrderType;
using spot_sbe::SelfTradePreventionMode;
using spot_sbe::TimeInForce;

struct GetOrder {
    int64_t order_id;
    std::optional<int64_t> order_list_id;
    Decimal price;
    Decimal orig_qty;
    Decimal executed_qty;
    Decimal cummulative_quote_qty;
    OrderStatus::Value status;
    TimeInForce::Value time_in_force;
    OrderType::Value order_type;
    OrderSide::Value side;
    std::optional<Decimal> stop_price;
    std::optional<int64_t> trailing_delta;
    std::optional<int64_t> trailing_time;
    std::optional<Decimal> iceberg_qty;
    int64_t time;
    int64_t update_time;
    bool is_working;
    std::optional<int64_t> working_time;
    Decimal orig_quote_order_qty;
    std::optional<int64_t> strategy_id;
    std::optional<int32_t> strategy_type;
    std::optional<OrderCapacity::Value> order_capacity;
    std::optional<Floor::Value> working_floor;
    SelfTradePreventionMode::Value self_trade_prevention_mode;
    std::optional<int64_t> prevented_match_id;
    std::optional<Decimal> prevented_quantity;
    std::optional<bool> used_sor;
    std::string symbol;
    std::string client_order_id;
};

#endif
