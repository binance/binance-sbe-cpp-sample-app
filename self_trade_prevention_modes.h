#ifndef _SBE_APP_SELF_TRADE_PREVENT_MODES_H_
#define _SBE_APP_SELF_TRADE_PREVENT_MODES_H_

#include <unistd.h>
#include "spot_sbe/AllowedSelfTradePreventionModes.h"

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

#endif
