/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_TICKERMINIRESPONSE_CXX_H_
#define _SPOT_SBE_TICKERMINIRESPONSE_CXX_H_

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


#include "OrderType.h"
#include "VarString.h"
#include "MatchType.h"
#include "BoolEnum.h"
#include "OrderStatus.h"
#include "GroupSizeEncoding.h"
#include "GroupSize16Encoding.h"
#include "OptionalMessageData.h"
#include "ContingencyType.h"
#include "ListOrderStatus.h"
#include "MessageData8.h"
#include "RateLimitInterval.h"
#include "Floor.h"
#include "TimeInForce.h"
#include "ListStatusType.h"
#include "AllowedSelfTradePreventionModes.h"
#include "MessageHeader.h"
#include "AccountType.h"
#include "OptionalMessageData16.h"
#include "OrderCapacity.h"
#include "AllocationType.h"
#include "OptionalVarString.h"
#include "OrderSide.h"
#include "OrderTypes.h"
#include "SelfTradePreventionMode.h"
#include "CancelReplaceStatus.h"
#include "SymbolStatus.h"
#include "OptionalVarString8.h"
#include "RateLimitType.h"
#include "MessageData16.h"
#include "FilterType.h"
#include "VarString8.h"
#include "MessageData.h"

namespace spot_sbe {

class TickerMiniResponse
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_position = 0;
    std::uint64_t m_actingBlockLength = 0;
    std::uint64_t m_actingVersion = 0;

    inline std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
    {
        return &m_position;
    }

public:
    static const std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(0);
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(216);
    static const std::uint16_t SBE_SCHEMA_ID = static_cast<std::uint16_t>(1);
    static const std::uint16_t SBE_SCHEMA_VERSION = static_cast<std::uint16_t>(0);
    static constexpr const char* SBE_SEMANTIC_VERSION = "5.2";

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

    using messageHeader = MessageHeader;

    TickerMiniResponse() = default;

    TickerMiniResponse(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_position(sbeCheckPosition(offset + actingBlockLength)),
        m_actingBlockLength(actingBlockLength),
        m_actingVersion(actingVersion)
    {
    }

    TickerMiniResponse(char *buffer, const std::uint64_t bufferLength) :
        TickerMiniResponse(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    TickerMiniResponse(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        TickerMiniResponse(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(0);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(216);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(0);
    }

    SBE_NODISCARD static const char *sbeSemanticVersion() SBE_NOEXCEPT
    {
        return "5.2";
    }

    SBE_NODISCARD static SBE_CONSTEXPR const char *sbeSemanticType() SBE_NOEXCEPT
    {
        return "";
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    TickerMiniResponse &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    TickerMiniResponse &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        messageHeader hdr(buffer, offset, bufferLength, sbeSchemaVersion());

        hdr
            .blockLength(sbeBlockLength())
            .templateId(sbeTemplateId())
            .schemaId(sbeSchemaId())
            .version(sbeSchemaVersion());

        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset + messageHeader::encodedLength();
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    TickerMiniResponse &wrapForDecode(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = actingBlockLength;
        m_actingVersion = actingVersion;
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    TickerMiniResponse &sbeRewind()
    {
        return wrapForDecode(m_buffer, m_offset, m_actingBlockLength, m_actingVersion, m_bufferLength);
    }

    SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
    {
        return m_position;
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    std::uint64_t sbeCheckPosition(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        return position;
    }

    void sbePosition(const std::uint64_t position)
    {
        m_position = sbeCheckPosition(position);
    }

    SBE_NODISCARD std::uint64_t encodedLength() const SBE_NOEXCEPT
    {
        return sbePosition() - m_offset;
    }

    SBE_NODISCARD std::uint64_t decodeLength() const
    {
        TickerMiniResponse skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
        skipper.skip();
        return skipper.encodedLength();
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

    class Tickers
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        Tickers() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 6;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint32_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 2147483647)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSizeEncoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(106));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 106;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 6;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 6;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 106;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline Tickers &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex()
        {
            m_count = m_index;
            GroupSizeEncoding dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint32_t>(m_count));
            return m_count;
        }

        template<class Func> inline void forEach(Func &&func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }


        SBE_NODISCARD static const char *priceExponentMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t priceExponentId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceExponentSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool priceExponentInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceExponentEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::int8_t priceExponentNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT8;
        }

        static SBE_CONSTEXPR std::int8_t priceExponentMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(-127);
        }

        static SBE_CONSTEXPR std::int8_t priceExponentMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(127);
        }

        static SBE_CONSTEXPR std::size_t priceExponentEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::int8_t priceExponent() const SBE_NOEXCEPT
        {
            std::int8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int8_t));
            return (val);
        }

        Tickers &priceExponent(const std::int8_t value) SBE_NOEXCEPT
        {
            std::int8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int8_t));
            return *this;
        }

        SBE_NODISCARD static const char *qtyExponentMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t qtyExponentId() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t qtyExponentSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool qtyExponentInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t qtyExponentEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        static SBE_CONSTEXPR std::int8_t qtyExponentNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT8;
        }

        static SBE_CONSTEXPR std::int8_t qtyExponentMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(-127);
        }

        static SBE_CONSTEXPR std::int8_t qtyExponentMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(127);
        }

        static SBE_CONSTEXPR std::size_t qtyExponentEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::int8_t qtyExponent() const SBE_NOEXCEPT
        {
            std::int8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::int8_t));
            return (val);
        }

        Tickers &qtyExponent(const std::int8_t value) SBE_NOEXCEPT
        {
            std::int8_t val = (value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::int8_t));
            return *this;
        }

        SBE_NODISCARD static const char *openPriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t openPriceId() SBE_NOEXCEPT
        {
            return 3;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t openPriceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool openPriceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t openPriceEncodingOffset() SBE_NOEXCEPT
        {
            return 2;
        }

        static SBE_CONSTEXPR std::int64_t openPriceNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t openPriceMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t openPriceMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t openPriceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t openPrice() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &openPrice(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *highPriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t highPriceId() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t highPriceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool highPriceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t highPriceEncodingOffset() SBE_NOEXCEPT
        {
            return 10;
        }

        static SBE_CONSTEXPR std::int64_t highPriceNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t highPriceMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t highPriceMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t highPriceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t highPrice() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &highPrice(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 10, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *lowPriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t lowPriceId() SBE_NOEXCEPT
        {
            return 5;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lowPriceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool lowPriceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t lowPriceEncodingOffset() SBE_NOEXCEPT
        {
            return 18;
        }

        static SBE_CONSTEXPR std::int64_t lowPriceNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t lowPriceMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t lowPriceMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t lowPriceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t lowPrice() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 18, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &lowPrice(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 18, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *lastPriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t lastPriceId() SBE_NOEXCEPT
        {
            return 6;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lastPriceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool lastPriceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t lastPriceEncodingOffset() SBE_NOEXCEPT
        {
            return 26;
        }

        static SBE_CONSTEXPR std::int64_t lastPriceNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t lastPriceMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t lastPriceMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t lastPriceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t lastPrice() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 26, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &lastPrice(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 26, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *volumeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t volumeId() SBE_NOEXCEPT
        {
            return 7;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t volumeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool volumeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t volumeEncodingOffset() SBE_NOEXCEPT
        {
            return 34;
        }

        static SBE_CONSTEXPR std::uint8_t volumeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t volumeMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t volumeMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t volumeEncodingLength() SBE_NOEXCEPT
        {
            return 16;
        }

        static SBE_CONSTEXPR std::uint64_t volumeLength() SBE_NOEXCEPT
        {
            return 16;
        }

        SBE_NODISCARD const char *volume() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 34;
        }

        SBE_NODISCARD char *volume() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 34;
        }

        SBE_NODISCARD std::uint8_t volume(const std::uint64_t index) const
        {
            if (index >= 16)
            {
                throw std::runtime_error("index out of range for volume [E104]");
            }

            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 34 + (index * 1), sizeof(std::uint8_t));
            return (val);
        }

        Tickers &volume(const std::uint64_t index, const std::uint8_t value)
        {
            if (index >= 16)
            {
                throw std::runtime_error("index out of range for volume [E105]");
            }

            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 34 + (index * 1), &val, sizeof(std::uint8_t));
            return *this;
        }

        std::uint64_t getVolume(char *const dst, const std::uint64_t length) const
        {
            if (length > 16)
            {
                throw std::runtime_error("length too large for getVolume [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 34, sizeof(std::uint8_t) * static_cast<std::size_t>(length));
            return length;
        }

        Tickers &putVolume(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 34, src, sizeof(std::uint8_t) * 16);
            return *this;
        }

        SBE_NODISCARD static const char *quoteVolumeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t quoteVolumeId() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t quoteVolumeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool quoteVolumeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t quoteVolumeEncodingOffset() SBE_NOEXCEPT
        {
            return 50;
        }

        static SBE_CONSTEXPR std::uint8_t quoteVolumeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t quoteVolumeMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t quoteVolumeMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t quoteVolumeEncodingLength() SBE_NOEXCEPT
        {
            return 16;
        }

        static SBE_CONSTEXPR std::uint64_t quoteVolumeLength() SBE_NOEXCEPT
        {
            return 16;
        }

        SBE_NODISCARD const char *quoteVolume() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 50;
        }

        SBE_NODISCARD char *quoteVolume() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 50;
        }

        SBE_NODISCARD std::uint8_t quoteVolume(const std::uint64_t index) const
        {
            if (index >= 16)
            {
                throw std::runtime_error("index out of range for quoteVolume [E104]");
            }

            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 50 + (index * 1), sizeof(std::uint8_t));
            return (val);
        }

        Tickers &quoteVolume(const std::uint64_t index, const std::uint8_t value)
        {
            if (index >= 16)
            {
                throw std::runtime_error("index out of range for quoteVolume [E105]");
            }

            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 50 + (index * 1), &val, sizeof(std::uint8_t));
            return *this;
        }

        std::uint64_t getQuoteVolume(char *const dst, const std::uint64_t length) const
        {
            if (length > 16)
            {
                throw std::runtime_error("length too large for getQuoteVolume [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 50, sizeof(std::uint8_t) * static_cast<std::size_t>(length));
            return length;
        }

        Tickers &putQuoteVolume(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 50, src, sizeof(std::uint8_t) * 16);
            return *this;
        }

        SBE_NODISCARD static const char *openTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t openTimeId() SBE_NOEXCEPT
        {
            return 9;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t openTimeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool openTimeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t openTimeEncodingOffset() SBE_NOEXCEPT
        {
            return 66;
        }

        static SBE_CONSTEXPR std::int64_t openTimeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t openTimeMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t openTimeMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t openTimeEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t openTime() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 66, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &openTime(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 66, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *closeTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t closeTimeId() SBE_NOEXCEPT
        {
            return 10;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t closeTimeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool closeTimeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t closeTimeEncodingOffset() SBE_NOEXCEPT
        {
            return 74;
        }

        static SBE_CONSTEXPR std::int64_t closeTimeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t closeTimeMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t closeTimeMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t closeTimeEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t closeTime() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 74, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &closeTime(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 74, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *firstIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t firstIdId() SBE_NOEXCEPT
        {
            return 11;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t firstIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool firstIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t firstIdEncodingOffset() SBE_NOEXCEPT
        {
            return 82;
        }

        static SBE_CONSTEXPR std::int64_t firstIdNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t firstIdMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t firstIdMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t firstIdEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t firstId() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 82, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &firstId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 82, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *lastIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t lastIdId() SBE_NOEXCEPT
        {
            return 12;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lastIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool lastIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t lastIdEncodingOffset() SBE_NOEXCEPT
        {
            return 90;
        }

        static SBE_CONSTEXPR std::int64_t lastIdNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t lastIdMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t lastIdMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t lastIdEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t lastId() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 90, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &lastId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 90, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *numTradesMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t numTradesId() SBE_NOEXCEPT
        {
            return 13;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t numTradesSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool numTradesInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t numTradesEncodingOffset() SBE_NOEXCEPT
        {
            return 98;
        }

        static SBE_CONSTEXPR std::int64_t numTradesNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t numTradesMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t numTradesMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t numTradesEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t numTrades() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 98, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Tickers &numTrades(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 98, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *symbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *symbolCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t symbolSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool symbolInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t symbolId() SBE_NOEXCEPT
        {
            return 200;
        }

        static SBE_CONSTEXPR std::uint64_t symbolHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t symbolLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipSymbol()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *symbol()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getSymbol(char *dst, const std::uint64_t length)
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            sbePosition(lengthPosition + lengthOfLengthField);
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            std::uint64_t bytesToCopy = length < dataLength ? length : dataLength;
            std::uint64_t pos = sbePosition();
            sbePosition(pos + dataLength);
            std::memcpy(dst, m_buffer + pos, static_cast<std::size_t>(bytesToCopy));
            return bytesToCopy;
        }

        Tickers &putSymbol(const char *src, const std::uint8_t length)
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue = (length);
            sbePosition(lengthPosition + lengthOfLengthField);
            std::memcpy(m_buffer + lengthPosition, &lengthFieldValue, sizeof(std::uint8_t));
            if (length != std::uint8_t(0))
            {
                std::uint64_t pos = sbePosition();
                sbePosition(pos + length);
                std::memcpy(m_buffer + pos, src, length);
            }
            return *this;
        }

        std::string getSymbolAsString()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            sbePosition(lengthPosition + lengthOfLengthField);
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            std::uint64_t pos = sbePosition();
            const std::string result(m_buffer + pos, dataLength);
            sbePosition(pos + dataLength);
            return result;
        }

        std::string getSymbolAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getSymbolAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        std::string_view getSymbolAsStringView()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            sbePosition(lengthPosition + lengthOfLengthField);
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            std::uint64_t pos = sbePosition();
            const std::string_view result(m_buffer + pos, dataLength);
            sbePosition(pos + dataLength);
            return result;
        }
        #endif

        Tickers &putSymbol(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Tickers &putSymbol(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, Tickers &writer)
        {
            builder << '{';
            builder << R"("priceExponent": )";
            builder << +writer.priceExponent();

            builder << ", ";
            builder << R"("qtyExponent": )";
            builder << +writer.qtyExponent();

            builder << ", ";
            builder << R"("openPrice": )";
            builder << +writer.openPrice();

            builder << ", ";
            builder << R"("highPrice": )";
            builder << +writer.highPrice();

            builder << ", ";
            builder << R"("lowPrice": )";
            builder << +writer.lowPrice();

            builder << ", ";
            builder << R"("lastPrice": )";
            builder << +writer.lastPrice();

            builder << ", ";
            builder << R"("volume": )";
            builder << '[';
            for (std::size_t i = 0, length = writer.volumeLength(); i < length; i++)
            {
                if (i)
                {
                    builder << ',';
                }
                builder << +writer.volume(i);
            }
            builder << ']';

            builder << ", ";
            builder << R"("quoteVolume": )";
            builder << '[';
            for (std::size_t i = 0, length = writer.quoteVolumeLength(); i < length; i++)
            {
                if (i)
                {
                    builder << ',';
                }
                builder << +writer.quoteVolume(i);
            }
            builder << ']';

            builder << ", ";
            builder << R"("openTime": )";
            builder << +writer.openTime();

            builder << ", ";
            builder << R"("closeTime": )";
            builder << +writer.closeTime();

            builder << ", ";
            builder << R"("firstId": )";
            builder << +writer.firstId();

            builder << ", ";
            builder << R"("lastId": )";
            builder << +writer.lastId();

            builder << ", ";
            builder << R"("numTrades": )";
            builder << +writer.numTrades();

            builder << ", ";
            builder << R"("symbol": )";
            builder << '"' <<
                writer.getSymbolAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
            skipSymbol();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(std::size_t symbolLength = 0)
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            length += symbolHeaderLength();
            if (symbolLength > 254LL)
            {
                throw std::runtime_error("symbolLength too long for length type [E109]");
            }
            length += symbolLength;

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    Tickers m_tickers;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t tickersId() SBE_NOEXCEPT
    {
        return 100;
    }

    SBE_NODISCARD inline Tickers &tickers()
    {
        m_tickers.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_tickers;
    }

    Tickers &tickersCount(const std::uint32_t count)
    {
        m_tickers.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_tickers;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tickersSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool tickersInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const TickerMiniResponse &_writer)
{
    TickerMiniResponse writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "TickerMiniResponse", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    {
        bool atLeastOne = false;
        builder << R"("tickers": [)";
        writer.tickers().forEach(
            [&](Tickers &tickers)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << tickers;
            });
        builder << ']';
    }

    builder << '}';

    return builder;
}

void skip()
{
    auto &tickersGroup { tickers() };
    while (tickersGroup.hasNext())
    {
        tickersGroup.next().skip();
    }
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(const std::vector<std::tuple<std::size_t>> &tickersItemLengths = {})
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += Tickers::sbeHeaderSize();
    if (tickersItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("tickersItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: tickersItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(Tickers::computeLength, e);
        #else
        length += Tickers::computeLength(std::get<0>(e));
        #endif
    }

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
