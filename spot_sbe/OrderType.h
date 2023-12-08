/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_ORDERTYPE_CXX_H_
#define _SPOT_SBE_ORDERTYPE_CXX_H_

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

class OrderType
{
public:
    enum Value
    {
        Market = static_cast<std::uint8_t>(0),
        Limit = static_cast<std::uint8_t>(1),
        StopLoss = static_cast<std::uint8_t>(2),
        StopLossLimit = static_cast<std::uint8_t>(3),
        TakeProfit = static_cast<std::uint8_t>(4),
        TakeProfitLimit = static_cast<std::uint8_t>(5),
        LimitMaker = static_cast<std::uint8_t>(6),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static OrderType::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return Market;
            case static_cast<std::uint8_t>(1): return Limit;
            case static_cast<std::uint8_t>(2): return StopLoss;
            case static_cast<std::uint8_t>(3): return StopLossLimit;
            case static_cast<std::uint8_t>(4): return TakeProfit;
            case static_cast<std::uint8_t>(5): return TakeProfitLimit;
            case static_cast<std::uint8_t>(6): return LimitMaker;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum OrderType [E103]");
    }

    static const char *c_str(const OrderType::Value value)
    {
        switch (value)
        {
            case Market: return "Market";
            case Limit: return "Limit";
            case StopLoss: return "StopLoss";
            case StopLossLimit: return "StopLossLimit";
            case TakeProfit: return "TakeProfit";
            case TakeProfitLimit: return "TakeProfitLimit";
            case LimitMaker: return "LimitMaker";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum OrderType [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, OrderType::Value m)
    {
        return os << OrderType::c_str(m);
    }
};

}

#endif
