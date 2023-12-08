/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_SYMBOLSTATUS_CXX_H_
#define _SPOT_SBE_SYMBOLSTATUS_CXX_H_

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

class SymbolStatus
{
public:
    enum Value
    {
        PreTrading = static_cast<std::uint8_t>(0),
        Trading = static_cast<std::uint8_t>(1),
        PostTrading = static_cast<std::uint8_t>(2),
        EndOfDay = static_cast<std::uint8_t>(3),
        Halt = static_cast<std::uint8_t>(4),
        AuctionMatch = static_cast<std::uint8_t>(5),
        Break = static_cast<std::uint8_t>(7),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static SymbolStatus::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return PreTrading;
            case static_cast<std::uint8_t>(1): return Trading;
            case static_cast<std::uint8_t>(2): return PostTrading;
            case static_cast<std::uint8_t>(3): return EndOfDay;
            case static_cast<std::uint8_t>(4): return Halt;
            case static_cast<std::uint8_t>(5): return AuctionMatch;
            case static_cast<std::uint8_t>(7): return Break;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SymbolStatus [E103]");
    }

    static const char *c_str(const SymbolStatus::Value value)
    {
        switch (value)
        {
            case PreTrading: return "PreTrading";
            case Trading: return "Trading";
            case PostTrading: return "PostTrading";
            case EndOfDay: return "EndOfDay";
            case Halt: return "Halt";
            case AuctionMatch: return "AuctionMatch";
            case Break: return "Break";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum SymbolStatus [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, SymbolStatus::Value m)
    {
        return os << SymbolStatus::c_str(m);
    }
};

}

#endif
