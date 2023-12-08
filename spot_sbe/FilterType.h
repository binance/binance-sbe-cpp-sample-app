/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_FILTERTYPE_CXX_H_
#define _SPOT_SBE_FILTERTYPE_CXX_H_

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

class FilterType
{
public:
    enum Value
    {
        MaxPosition = static_cast<std::uint8_t>(0),
        PriceFilter = static_cast<std::uint8_t>(1),
        TPlusSell = static_cast<std::uint8_t>(2),
        LotSize = static_cast<std::uint8_t>(3),
        MaxNumOrders = static_cast<std::uint8_t>(4),
        MinNotional = static_cast<std::uint8_t>(5),
        MaxNumAlgoOrders = static_cast<std::uint8_t>(6),
        ExchangeMaxNumOrders = static_cast<std::uint8_t>(7),
        ExchangeMaxNumAlgoOrders = static_cast<std::uint8_t>(8),
        IcebergParts = static_cast<std::uint8_t>(9),
        MarketLotSize = static_cast<std::uint8_t>(10),
        PercentPrice = static_cast<std::uint8_t>(11),
        MaxNumIcebergOrders = static_cast<std::uint8_t>(12),
        ExchangeMaxNumIcebergOrders = static_cast<std::uint8_t>(13),
        TrailingDelta = static_cast<std::uint8_t>(14),
        PercentPriceBySide = static_cast<std::uint8_t>(15),
        Notional = static_cast<std::uint8_t>(16),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static FilterType::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return MaxPosition;
            case static_cast<std::uint8_t>(1): return PriceFilter;
            case static_cast<std::uint8_t>(2): return TPlusSell;
            case static_cast<std::uint8_t>(3): return LotSize;
            case static_cast<std::uint8_t>(4): return MaxNumOrders;
            case static_cast<std::uint8_t>(5): return MinNotional;
            case static_cast<std::uint8_t>(6): return MaxNumAlgoOrders;
            case static_cast<std::uint8_t>(7): return ExchangeMaxNumOrders;
            case static_cast<std::uint8_t>(8): return ExchangeMaxNumAlgoOrders;
            case static_cast<std::uint8_t>(9): return IcebergParts;
            case static_cast<std::uint8_t>(10): return MarketLotSize;
            case static_cast<std::uint8_t>(11): return PercentPrice;
            case static_cast<std::uint8_t>(12): return MaxNumIcebergOrders;
            case static_cast<std::uint8_t>(13): return ExchangeMaxNumIcebergOrders;
            case static_cast<std::uint8_t>(14): return TrailingDelta;
            case static_cast<std::uint8_t>(15): return PercentPriceBySide;
            case static_cast<std::uint8_t>(16): return Notional;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum FilterType [E103]");
    }

    static const char *c_str(const FilterType::Value value)
    {
        switch (value)
        {
            case MaxPosition: return "MaxPosition";
            case PriceFilter: return "PriceFilter";
            case TPlusSell: return "TPlusSell";
            case LotSize: return "LotSize";
            case MaxNumOrders: return "MaxNumOrders";
            case MinNotional: return "MinNotional";
            case MaxNumAlgoOrders: return "MaxNumAlgoOrders";
            case ExchangeMaxNumOrders: return "ExchangeMaxNumOrders";
            case ExchangeMaxNumAlgoOrders: return "ExchangeMaxNumAlgoOrders";
            case IcebergParts: return "IcebergParts";
            case MarketLotSize: return "MarketLotSize";
            case PercentPrice: return "PercentPrice";
            case MaxNumIcebergOrders: return "MaxNumIcebergOrders";
            case ExchangeMaxNumIcebergOrders: return "ExchangeMaxNumIcebergOrders";
            case TrailingDelta: return "TrailingDelta";
            case PercentPriceBySide: return "PercentPriceBySide";
            case Notional: return "Notional";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum FilterType [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, FilterType::Value m)
    {
        return os << FilterType::c_str(m);
    }
};

}

#endif
