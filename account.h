#ifndef _SBE_APP_ACCOUNT_H_
#define _SBE_APP_ACCOUNT_H_

#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <optional>
#include <variant>
#include <vector>

#include "decimal.h"
#include "spot_sbe/AccountType.h"
#include "util.h"

using spot_sbe::AccountType;

struct CommissionRates {
    Decimal commission_rate_maker;
    Decimal commission_rate_taker;
    Decimal commission_rate_buyer;
    Decimal commission_rate_seller;

    CommissionRates(const int64_t commission_rate_maker,
                    const int64_t commission_rate_taker,
                    const int64_t commission_rate_buyer,
                    const int64_t commission_rate_seller,
                    const int8_t commission_exponent)
        : commission_rate_maker{commission_rate_maker, commission_exponent},
          commission_rate_taker{commission_rate_taker, commission_exponent},
          commission_rate_buyer{commission_rate_buyer, commission_exponent},
          commission_rate_seller{commission_rate_seller, commission_exponent} {}
};

struct Balances {
    Decimal free;
    Decimal locked;
    std::string asset;

    Balances(const int64_t free,
             const int64_t locked,
             std::string asset,
             const int8_t exponent)
        : free{free, exponent}, locked{locked, exponent}, asset{std::move(asset)} {}
};

struct Account {
    CommissionRates commission_rates;
    bool can_trade;
    bool can_withdraw;
    bool can_deposit;
    bool brokered;
    bool require_self_trade_prevention;
    bool prevent_sor;
    int64_t update_time;
    AccountType::Value account_type;
    std::optional<int16_t> trade_group_id;
    int64_t uid;
    std::vector<Balances> balances;
    std::vector<std::string> permissions;
    std::vector<std::string> reduce_only_assets;

    Account()
        : commission_rates{0, 0, 0, 0, 0},
          can_trade{false},
          can_withdraw{false},
          can_deposit{false},
          brokered{false},
          require_self_trade_prevention{false},
          prevent_sor{false},
          update_time{0},
          account_type{AccountType::NULL_VALUE},
          uid{0},
          balances{},
          permissions{},
          reduce_only_assets{} {}
};

#endif
