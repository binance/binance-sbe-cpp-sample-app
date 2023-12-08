/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_ORDERSTATUS_CXX_H_
#define _SPOT_SBE_ORDERSTATUS_CXX_H_

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

class OrderStatus
{
public:
    enum Value
    {
        New = static_cast<std::uint8_t>(0),
        PartiallyFilled = static_cast<std::uint8_t>(1),
        Filled = static_cast<std::uint8_t>(2),
        Canceled = static_cast<std::uint8_t>(3),
        PendingCancel = static_cast<std::uint8_t>(4),
        Rejected = static_cast<std::uint8_t>(5),
        Expired = static_cast<std::uint8_t>(6),
        ExpiredInMatch = static_cast<std::uint8_t>(9),
        Unknown = static_cast<std::uint8_t>(254),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static OrderStatus::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return New;
            case static_cast<std::uint8_t>(1): return PartiallyFilled;
            case static_cast<std::uint8_t>(2): return Filled;
            case static_cast<std::uint8_t>(3): return Canceled;
            case static_cast<std::uint8_t>(4): return PendingCancel;
            case static_cast<std::uint8_t>(5): return Rejected;
            case static_cast<std::uint8_t>(6): return Expired;
            case static_cast<std::uint8_t>(9): return ExpiredInMatch;
            case static_cast<std::uint8_t>(254): return Unknown;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum OrderStatus [E103]");
    }

    static const char *c_str(const OrderStatus::Value value)
    {
        switch (value)
        {
            case New: return "New";
            case PartiallyFilled: return "PartiallyFilled";
            case Filled: return "Filled";
            case Canceled: return "Canceled";
            case PendingCancel: return "PendingCancel";
            case Rejected: return "Rejected";
            case Expired: return "Expired";
            case ExpiredInMatch: return "ExpiredInMatch";
            case Unknown: return "Unknown";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum OrderStatus [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, OrderStatus::Value m)
    {
        return os << OrderStatus::c_str(m);
    }
};

}

#endif
