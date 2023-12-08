/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_ORDERTYPES_CXX_H_
#define _SPOT_SBE_ORDERTYPES_CXX_H_

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#  define SBE_NOEXCEPT noexcept
#else
#  define SBE_CONSTEXPR
#  define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#  include <string_view>
#  define SBE_NODISCARD [[nodiscard]]
#else
#  define SBE_NODISCARD
#endif

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <limits>
#include <cstring>
#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

#if defined(WIN32) || defined(_WIN32)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#  error "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#  if defined(SBE_NO_BOUNDS_CHECK)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#  elif defined(_MSC_VER)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#  else 
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#  endif

#endif

#define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()


namespace spot_sbe {

class OrderTypes
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_actingVersion = 0;

public:
    enum MetaAttribute
    {
        EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE
    };

    union sbe_float_as_uint_u
    {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u
    {
        double fp_value;
        std::uint64_t uint_value;
    };

    OrderTypes() = default;

    OrderTypes(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_actingVersion(actingVersion)
    {
        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 2) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }
    }

    OrderTypes(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingVersion) :
        OrderTypes(buffer, 0, bufferLength, actingVersion)
    {
    }

    OrderTypes(
        char *buffer,
        const std::uint64_t bufferLength) :
        OrderTypes(buffer, 0, bufferLength, sbeSchemaVersion())
    {
    }

    OrderTypes &wrap(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingVersion = actingVersion;

        if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + 2) > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short for flyweight [E107]");
        }

        return *this;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t encodedLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    SBE_NODISCARD const char *buffer() const SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD char *buffer() SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT
    {
        return m_bufferLength;
    }

    SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT
    {
        return m_actingVersion;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(0);
    }

    OrderTypes &clear()
    {
        std::uint16_t zero = 0;
        std::memcpy(m_buffer + m_offset, &zero, sizeof(std::uint16_t));
        return *this;
    }

    SBE_NODISCARD bool isEmpty() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return 0 == val;
    }

    SBE_NODISCARD std::uint16_t rawValue() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return val;
    }

    OrderTypes &rawValue(std::uint16_t value)
    {
        std::memcpy(m_buffer + m_offset, &value, sizeof(std::uint16_t));
        return *this;
    }

    static bool market(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 0u)) != 0;
    }

    static std::uint16_t market(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 0u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 0u));
    }

    SBE_NODISCARD bool market() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 0u)) != 0;
    }

    OrderTypes &market(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 0u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 0u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    static bool limit(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 1u)) != 0;
    }

    static std::uint16_t limit(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 1u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 1u));
    }

    SBE_NODISCARD bool limit() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 1u)) != 0;
    }

    OrderTypes &limit(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 1u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 1u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    static bool stopLoss(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 2u)) != 0;
    }

    static std::uint16_t stopLoss(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 2u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 2u));
    }

    SBE_NODISCARD bool stopLoss() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 2u)) != 0;
    }

    OrderTypes &stopLoss(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 2u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 2u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    static bool stopLossLimit(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 3u)) != 0;
    }

    static std::uint16_t stopLossLimit(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 3u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 3u));
    }

    SBE_NODISCARD bool stopLossLimit() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 3u)) != 0;
    }

    OrderTypes &stopLossLimit(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 3u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 3u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    static bool takeProfit(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 4u)) != 0;
    }

    static std::uint16_t takeProfit(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 4u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 4u));
    }

    SBE_NODISCARD bool takeProfit() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 4u)) != 0;
    }

    OrderTypes &takeProfit(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 4u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 4u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    static bool takeProfitLimit(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 5u)) != 0;
    }

    static std::uint16_t takeProfitLimit(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 5u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 5u));
    }

    SBE_NODISCARD bool takeProfitLimit() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 5u)) != 0;
    }

    OrderTypes &takeProfitLimit(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 5u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 5u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    static bool limitMaker(const std::uint16_t bits)
    {
        return (bits & (static_cast<std::uint16_t>(1) << 6u)) != 0;
    }

    static std::uint16_t limitMaker(const std::uint16_t bits, const bool value)
    {
        return value ? static_cast<std::uint16_t>(bits | (static_cast<std::uint16_t>(1) << 6u)) : static_cast<std::uint16_t>(bits & ~(static_cast<std::uint16_t>(1) << 6u));
    }

    SBE_NODISCARD bool limitMaker() const
    {
        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset, sizeof(std::uint16_t));
        return (SBE_LITTLE_ENDIAN_ENCODE_16(val) & (static_cast<std::uint16_t>(1) << 6u)) != 0;
    }

    OrderTypes &limitMaker(const bool value)
    {
        std::uint16_t bits;
        std::memcpy(&bits, m_buffer + m_offset, sizeof(std::uint16_t));
        bits = SBE_LITTLE_ENDIAN_ENCODE_16(value ? static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) | (static_cast<std::uint16_t>(1) << 6u)) : static_cast<std::uint16_t>(SBE_LITTLE_ENDIAN_ENCODE_16(bits) & ~(static_cast<std::uint16_t>(1) << 6u)));
        std::memcpy(m_buffer + m_offset, &bits, sizeof(std::uint16_t));
        return *this;
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &builder, OrderTypes &writer)
    {
        builder << '[';
        bool atLeastOne = false;
        if (writer.market())
        {
            builder << R"("market")";
            atLeastOne = true;
        }
        if (writer.limit())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("limit")";
            atLeastOne = true;
        }
        if (writer.stopLoss())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("stopLoss")";
            atLeastOne = true;
        }
        if (writer.stopLossLimit())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("stopLossLimit")";
            atLeastOne = true;
        }
        if (writer.takeProfit())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("takeProfit")";
            atLeastOne = true;
        }
        if (writer.takeProfitLimit())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("takeProfitLimit")";
            atLeastOne = true;
        }
        if (writer.limitMaker())
        {
            if (atLeastOne)
            {
                builder << ",";
            }
            builder << R"("limitMaker")";
        }
        builder << ']';
        return builder;
    }
};
}
#endif
