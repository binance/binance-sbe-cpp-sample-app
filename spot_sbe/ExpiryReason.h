/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_EXPIRYREASON_CXX_H_
#define _SPOT_SBE_EXPIRYREASON_CXX_H_

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

class ExpiryReason
{
public:
    enum Value
    {
        Rejected = static_cast<std::uint8_t>(1),
        ExchangeCanceled = static_cast<std::uint8_t>(2),
        OcoTrigger = static_cast<std::uint8_t>(3),
        OtoPhaseOneExpired = static_cast<std::uint8_t>(4),
        UnfilledIocQuantityExpired = static_cast<std::uint8_t>(5),
        UnfilledFokOrderExpired = static_cast<std::uint8_t>(6),
        InsufficientLiquidity = static_cast<std::uint8_t>(7),
        ExecutionRulePriceRangeExceeded = static_cast<std::uint8_t>(8),
        NonRepresentable = static_cast<std::uint8_t>(254),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static ExpiryReason::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(1): return Rejected;
            case static_cast<std::uint8_t>(2): return ExchangeCanceled;
            case static_cast<std::uint8_t>(3): return OcoTrigger;
            case static_cast<std::uint8_t>(4): return OtoPhaseOneExpired;
            case static_cast<std::uint8_t>(5): return UnfilledIocQuantityExpired;
            case static_cast<std::uint8_t>(6): return UnfilledFokOrderExpired;
            case static_cast<std::uint8_t>(7): return InsufficientLiquidity;
            case static_cast<std::uint8_t>(8): return ExecutionRulePriceRangeExceeded;
            case static_cast<std::uint8_t>(254): return NonRepresentable;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum ExpiryReason [E103]");
    }

    static const char *c_str(const ExpiryReason::Value value)
    {
        switch (value)
        {
            case Rejected: return "Rejected";
            case ExchangeCanceled: return "ExchangeCanceled";
            case OcoTrigger: return "OcoTrigger";
            case OtoPhaseOneExpired: return "OtoPhaseOneExpired";
            case UnfilledIocQuantityExpired: return "UnfilledIocQuantityExpired";
            case UnfilledFokOrderExpired: return "UnfilledFokOrderExpired";
            case InsufficientLiquidity: return "InsufficientLiquidity";
            case ExecutionRulePriceRangeExceeded: return "ExecutionRulePriceRangeExceeded";
            case NonRepresentable: return "NonRepresentable";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum ExpiryReason [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, ExpiryReason::Value m)
    {
        return os << ExpiryReason::c_str(m);
    }
};

}

#endif
