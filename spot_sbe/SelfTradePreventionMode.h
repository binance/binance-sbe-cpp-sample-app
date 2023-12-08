/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_SELFTRADEPREVENTIONMODE_CXX_H_
#define _SPOT_SBE_SELFTRADEPREVENTIONMODE_CXX_H_

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <iomanip>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>

#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

namespace spot_sbe {

class SelfTradePreventionMode
{
public:
    enum Value
    {
        None = static_cast<std::uint8_t>(1),
        ExpireTaker = static_cast<std::uint8_t>(2),
        ExpireMaker = static_cast<std::uint8_t>(3),
        ExpireBoth = static_cast<std::uint8_t>(4),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static SelfTradePreventionMode::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(1): return None;
            case static_cast<std::uint8_t>(2): return ExpireTaker;
            case static_cast<std::uint8_t>(3): return ExpireMaker;
            case static_cast<std::uint8_t>(4): return ExpireBoth;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SelfTradePreventionMode [E103]");
    }

    static const char *c_str(const SelfTradePreventionMode::Value value)
    {
        switch (value)
        {
            case None: return "None";
            case ExpireTaker: return "ExpireTaker";
            case ExpireMaker: return "ExpireMaker";
            case ExpireBoth: return "ExpireBoth";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum SelfTradePreventionMode [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, SelfTradePreventionMode::Value m)
    {
        return os << SelfTradePreventionMode::c_str(m);
    }
};

}

#endif
