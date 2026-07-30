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
        Trading = static_cast<std::uint8_t>(0),
        EndOfDay = static_cast<std::uint8_t>(1),
        Halt = static_cast<std::uint8_t>(2),
        Break = static_cast<std::uint8_t>(3),
        CancelOnly = static_cast<std::uint8_t>(4),
        NonRepresentable = static_cast<std::uint8_t>(254),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static SymbolStatus::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return Trading;
            case static_cast<std::uint8_t>(1): return EndOfDay;
            case static_cast<std::uint8_t>(2): return Halt;
            case static_cast<std::uint8_t>(3): return Break;
            case static_cast<std::uint8_t>(4): return CancelOnly;
            case static_cast<std::uint8_t>(254): return NonRepresentable;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum SymbolStatus [E103]");
    }

    static const char *c_str(const SymbolStatus::Value value)
    {
        switch (value)
        {
            case Trading: return "Trading";
            case EndOfDay: return "EndOfDay";
            case Halt: return "Halt";
            case Break: return "Break";
            case CancelOnly: return "CancelOnly";
            case NonRepresentable: return "NonRepresentable";
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
