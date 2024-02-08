/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_EXCHANGEINFORESPONSE_CXX_H_
#define _SPOT_SBE_EXCHANGEINFORESPONSE_CXX_H_

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

class ExchangeInfoResponse
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
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(103);
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

    ExchangeInfoResponse() = default;

    ExchangeInfoResponse(
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

    ExchangeInfoResponse(char *buffer, const std::uint64_t bufferLength) :
        ExchangeInfoResponse(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    ExchangeInfoResponse(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        ExchangeInfoResponse(buffer, 0, bufferLength, actingBlockLength, actingVersion)
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
        return static_cast<std::uint16_t>(103);
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

    ExchangeInfoResponse &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    ExchangeInfoResponse &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
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

    ExchangeInfoResponse &wrapForDecode(
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

    ExchangeInfoResponse &sbeRewind()
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
        ExchangeInfoResponse skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
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

    class RateLimits
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
        RateLimits() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(11));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 11;
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
            return 11;
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

        inline RateLimits &next()
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


        SBE_NODISCARD static const char *rateLimitTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t rateLimitTypeId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t rateLimitTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool rateLimitTypeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t rateLimitTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t rateLimitTypeEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t rateLimitTypeRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD RateLimitType::Value rateLimitType() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return RateLimitType::get((val));
        }

        RateLimits &rateLimitType(const RateLimitType::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *intervalMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t intervalId() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t intervalSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool intervalInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t intervalEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t intervalEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t intervalRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD RateLimitInterval::Value interval() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return RateLimitInterval::get((val));
        }

        RateLimits &interval(const RateLimitInterval::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *intervalNumMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t intervalNumId() SBE_NOEXCEPT
        {
            return 3;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t intervalNumSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool intervalNumInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t intervalNumEncodingOffset() SBE_NOEXCEPT
        {
            return 2;
        }

        static SBE_CONSTEXPR std::uint8_t intervalNumNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t intervalNumMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t intervalNumMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t intervalNumEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t intervalNum() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::uint8_t));
            return (val);
        }

        RateLimits &intervalNum(const std::uint8_t value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *rateLimitMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t rateLimitId() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t rateLimitSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool rateLimitInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t rateLimitEncodingOffset() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::int64_t rateLimitNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t rateLimitMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t rateLimitMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t rateLimitEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t rateLimit() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 3, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        RateLimits &rateLimit(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 3, &val, sizeof(std::int64_t));
            return *this;
        }

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, RateLimits &writer)
        {
            builder << '{';
            builder << R"("rateLimitType": )";
            builder << '"' << writer.rateLimitType() << '"';

            builder << ", ";
            builder << R"("interval": )";
            builder << '"' << writer.interval() << '"';

            builder << ", ";
            builder << R"("intervalNum": )";
            builder << +writer.intervalNum();

            builder << ", ";
            builder << R"("rateLimit": )";
            builder << +writer.rateLimit();

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    RateLimits m_rateLimits;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t rateLimitsId() SBE_NOEXCEPT
    {
        return 100;
    }

    SBE_NODISCARD inline RateLimits &rateLimits()
    {
        m_rateLimits.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_rateLimits;
    }

    RateLimits &rateLimitsCount(const std::uint32_t count)
    {
        m_rateLimits.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_rateLimits;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t rateLimitsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool rateLimitsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class ExchangeFilters
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
        ExchangeFilters() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(0));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 0;
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
            return 0;
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

        inline ExchangeFilters &next()
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


        SBE_NODISCARD static const char *filterMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *filterCharacterEncoding() SBE_NOEXCEPT
        {
            return "null";
        }

        static SBE_CONSTEXPR std::uint64_t filterSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool filterInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t filterId() SBE_NOEXCEPT
        {
            return 200;
        }

        static SBE_CONSTEXPR std::uint64_t filterHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t filterLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipFilter()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *filter()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getFilter(char *dst, const std::uint64_t length)
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

        ExchangeFilters &putFilter(const char *src, const std::uint8_t length)
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

        std::string getFilterAsString()
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

        std::string getFilterAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getFilterAsString();

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
        std::string_view getFilterAsStringView()
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

        ExchangeFilters &putFilter(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putFilter(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        ExchangeFilters &putFilter(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putFilter(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, ExchangeFilters &writer)
        {
            builder << '{';
            builder << R"("filter": )";
            builder << '"' <<
                writer.skipFilter() << " bytes of raw data\"";
            builder << '}';

            return builder;
        }

        void skip()
        {
            skipFilter();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(std::size_t filterLength = 0)
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            length += filterHeaderLength();
            if (filterLength > 254LL)
            {
                throw std::runtime_error("filterLength too long for length type [E109]");
            }
            length += filterLength;

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    ExchangeFilters m_exchangeFilters;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t exchangeFiltersId() SBE_NOEXCEPT
    {
        return 101;
    }

    SBE_NODISCARD inline ExchangeFilters &exchangeFilters()
    {
        m_exchangeFilters.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_exchangeFilters;
    }

    ExchangeFilters &exchangeFiltersCount(const std::uint32_t count)
    {
        m_exchangeFilters.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_exchangeFilters;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exchangeFiltersSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool exchangeFiltersInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class Symbols
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
        Symbols() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(16));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 16;
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
            return 16;
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

        inline Symbols &next()
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


        SBE_NODISCARD static const char *statusMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t statusId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t statusSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool statusInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t statusEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t statusEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t statusRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD SymbolStatus::Value status() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return SymbolStatus::get((val));
        }

        Symbols &status(const SymbolStatus::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *baseAssetPrecisionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t baseAssetPrecisionId() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t baseAssetPrecisionSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool baseAssetPrecisionInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t baseAssetPrecisionEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        static SBE_CONSTEXPR std::uint8_t baseAssetPrecisionNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t baseAssetPrecisionMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t baseAssetPrecisionMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t baseAssetPrecisionEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t baseAssetPrecision() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return (val);
        }

        Symbols &baseAssetPrecision(const std::uint8_t value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *quoteAssetPrecisionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t quoteAssetPrecisionId() SBE_NOEXCEPT
        {
            return 3;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t quoteAssetPrecisionSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool quoteAssetPrecisionInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t quoteAssetPrecisionEncodingOffset() SBE_NOEXCEPT
        {
            return 2;
        }

        static SBE_CONSTEXPR std::uint8_t quoteAssetPrecisionNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t quoteAssetPrecisionMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t quoteAssetPrecisionMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t quoteAssetPrecisionEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t quoteAssetPrecision() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::uint8_t));
            return (val);
        }

        Symbols &quoteAssetPrecision(const std::uint8_t value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *baseCommissionPrecisionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t baseCommissionPrecisionId() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t baseCommissionPrecisionSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool baseCommissionPrecisionInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t baseCommissionPrecisionEncodingOffset() SBE_NOEXCEPT
        {
            return 3;
        }

        static SBE_CONSTEXPR std::uint8_t baseCommissionPrecisionNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t baseCommissionPrecisionMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t baseCommissionPrecisionMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t baseCommissionPrecisionEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t baseCommissionPrecision() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 3, sizeof(std::uint8_t));
            return (val);
        }

        Symbols &baseCommissionPrecision(const std::uint8_t value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 3, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *quoteCommissionPrecisionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t quoteCommissionPrecisionId() SBE_NOEXCEPT
        {
            return 5;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t quoteCommissionPrecisionSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool quoteCommissionPrecisionInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t quoteCommissionPrecisionEncodingOffset() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint8_t quoteCommissionPrecisionNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_UINT8;
        }

        static SBE_CONSTEXPR std::uint8_t quoteCommissionPrecisionMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(0);
        }

        static SBE_CONSTEXPR std::uint8_t quoteCommissionPrecisionMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::uint8_t>(254);
        }

        static SBE_CONSTEXPR std::size_t quoteCommissionPrecisionEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t quoteCommissionPrecision() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 4, sizeof(std::uint8_t));
            return (val);
        }

        Symbols &quoteCommissionPrecision(const std::uint8_t value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 4, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *orderTypesMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t orderTypesId() SBE_NOEXCEPT
        {
            return 6;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t orderTypesSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool orderTypesInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderTypesEncodingOffset() SBE_NOEXCEPT
        {
            return 5;
        }

    private:
        OrderTypes m_orderTypes;

    public:
        SBE_NODISCARD OrderTypes &orderTypes()
        {
            m_orderTypes.wrap(m_buffer, m_offset + 5, m_actingVersion, m_bufferLength);
            return m_orderTypes;
        }

        static SBE_CONSTEXPR std::size_t orderTypesEncodingLength() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static const char *icebergAllowedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t icebergAllowedId() SBE_NOEXCEPT
        {
            return 7;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t icebergAllowedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool icebergAllowedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t icebergAllowedEncodingOffset() SBE_NOEXCEPT
        {
            return 7;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t icebergAllowedEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t icebergAllowedRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 7, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value icebergAllowed() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 7, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &icebergAllowed(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 7, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *ocoAllowedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t ocoAllowedId() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t ocoAllowedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool ocoAllowedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t ocoAllowedEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t ocoAllowedEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t ocoAllowedRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value ocoAllowed() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &ocoAllowed(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *quoteOrderQtyMarketAllowedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t quoteOrderQtyMarketAllowedId() SBE_NOEXCEPT
        {
            return 9;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t quoteOrderQtyMarketAllowedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool quoteOrderQtyMarketAllowedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t quoteOrderQtyMarketAllowedEncodingOffset() SBE_NOEXCEPT
        {
            return 9;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t quoteOrderQtyMarketAllowedEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t quoteOrderQtyMarketAllowedRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 9, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value quoteOrderQtyMarketAllowed() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 9, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &quoteOrderQtyMarketAllowed(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 9, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *allowTrailingStopMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t allowTrailingStopId() SBE_NOEXCEPT
        {
            return 10;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allowTrailingStopSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool allowTrailingStopInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t allowTrailingStopEncodingOffset() SBE_NOEXCEPT
        {
            return 10;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t allowTrailingStopEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t allowTrailingStopRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value allowTrailingStop() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &allowTrailingStop(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 10, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *cancelReplaceAllowedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t cancelReplaceAllowedId() SBE_NOEXCEPT
        {
            return 11;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t cancelReplaceAllowedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool cancelReplaceAllowedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t cancelReplaceAllowedEncodingOffset() SBE_NOEXCEPT
        {
            return 11;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t cancelReplaceAllowedEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t cancelReplaceAllowedRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 11, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value cancelReplaceAllowed() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 11, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &cancelReplaceAllowed(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 11, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *isSpotTradingAllowedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t isSpotTradingAllowedId() SBE_NOEXCEPT
        {
            return 12;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t isSpotTradingAllowedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool isSpotTradingAllowedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t isSpotTradingAllowedEncodingOffset() SBE_NOEXCEPT
        {
            return 12;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t isSpotTradingAllowedEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t isSpotTradingAllowedRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 12, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value isSpotTradingAllowed() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 12, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &isSpotTradingAllowed(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 12, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *isMarginTradingAllowedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t isMarginTradingAllowedId() SBE_NOEXCEPT
        {
            return 13;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t isMarginTradingAllowedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool isMarginTradingAllowedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t isMarginTradingAllowedEncodingOffset() SBE_NOEXCEPT
        {
            return 13;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t isMarginTradingAllowedEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t isMarginTradingAllowedRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 13, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD BoolEnum::Value isMarginTradingAllowed() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 13, sizeof(std::uint8_t));
            return BoolEnum::get((val));
        }

        Symbols &isMarginTradingAllowed(const BoolEnum::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 13, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *defaultSelfTradePreventionModeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t defaultSelfTradePreventionModeId() SBE_NOEXCEPT
        {
            return 14;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t defaultSelfTradePreventionModeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool defaultSelfTradePreventionModeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t defaultSelfTradePreventionModeEncodingOffset() SBE_NOEXCEPT
        {
            return 14;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t defaultSelfTradePreventionModeEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t defaultSelfTradePreventionModeRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 14, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD SelfTradePreventionMode::Value defaultSelfTradePreventionMode() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 14, sizeof(std::uint8_t));
            return SelfTradePreventionMode::get((val));
        }

        Symbols &defaultSelfTradePreventionMode(const SelfTradePreventionMode::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 14, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *allowedSelfTradePreventionModesMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t allowedSelfTradePreventionModesId() SBE_NOEXCEPT
        {
            return 15;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allowedSelfTradePreventionModesSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool allowedSelfTradePreventionModesInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t allowedSelfTradePreventionModesEncodingOffset() SBE_NOEXCEPT
        {
            return 15;
        }

    private:
        AllowedSelfTradePreventionModes m_allowedSelfTradePreventionModes;

    public:
        SBE_NODISCARD AllowedSelfTradePreventionModes &allowedSelfTradePreventionModes()
        {
            m_allowedSelfTradePreventionModes.wrap(m_buffer, m_offset + 15, m_actingVersion, m_bufferLength);
            return m_allowedSelfTradePreventionModes;
        }

        static SBE_CONSTEXPR std::size_t allowedSelfTradePreventionModesEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        class Filters
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
            Filters() = default;

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
                dimensions.blockLength(static_cast<std::uint16_t>(0));
                dimensions.numInGroup(static_cast<std::uint32_t>(count));
                m_index = 0;
                m_count = count;
                m_blockLength = 0;
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
                return 0;
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

            inline Filters &next()
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


            SBE_NODISCARD static const char *filterMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
            {
                switch (metaAttribute)
                {
                    case MetaAttribute::PRESENCE: return "required";
                    default: return "";
                }
            }

            static const char *filterCharacterEncoding() SBE_NOEXCEPT
            {
                return "null";
            }

            static SBE_CONSTEXPR std::uint64_t filterSinceVersion() SBE_NOEXCEPT
            {
                return 0;
            }

            bool filterInActingVersion() SBE_NOEXCEPT
            {
                return true;
            }

            static SBE_CONSTEXPR std::uint16_t filterId() SBE_NOEXCEPT
            {
                return 200;
            }

            static SBE_CONSTEXPR std::uint64_t filterHeaderLength() SBE_NOEXCEPT
            {
                return 1;
            }

            SBE_NODISCARD std::uint8_t filterLength() const
            {
                std::uint8_t length;
                std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
                return (length);
            }

            std::uint64_t skipFilter()
            {
                std::uint64_t lengthOfLengthField = 1;
                std::uint64_t lengthPosition = sbePosition();
                std::uint8_t lengthFieldValue;
                std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
                std::uint64_t dataLength = (lengthFieldValue);
                sbePosition(lengthPosition + lengthOfLengthField + dataLength);
                return dataLength;
            }

            SBE_NODISCARD const char *filter()
            {
                std::uint8_t lengthFieldValue;
                std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
                const char *fieldPtr = m_buffer + sbePosition() + 1;
                sbePosition(sbePosition() + 1 + (lengthFieldValue));
                return fieldPtr;
            }

            std::uint64_t getFilter(char *dst, const std::uint64_t length)
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

            Filters &putFilter(const char *src, const std::uint8_t length)
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

            std::string getFilterAsString()
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

            std::string getFilterAsJsonEscapedString()
            {
                std::ostringstream oss;
                std::string s = getFilterAsString();

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
            std::string_view getFilterAsStringView()
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

            Filters &putFilter(const std::string &str)
            {
                if (str.length() > 254)
                {
                    throw std::runtime_error("std::string too long for length type [E109]");
                }
                return putFilter(str.data(), static_cast<std::uint8_t>(str.length()));
            }

            #if __cplusplus >= 201703L
            Filters &putFilter(const std::string_view str)
            {
                if (str.length() > 254)
                {
                    throw std::runtime_error("std::string too long for length type [E109]");
                }
                return putFilter(str.data(), static_cast<std::uint8_t>(str.length()));
            }
            #endif

            template<typename CharT, typename Traits>
            friend std::basic_ostream<CharT, Traits> & operator << (
                std::basic_ostream<CharT, Traits> &builder, Filters &writer)
            {
                builder << '{';
                builder << R"("filter": )";
                builder << '"' <<
                    writer.skipFilter() << " bytes of raw data\"";
                builder << '}';

                return builder;
            }

            void skip()
            {
                skipFilter();
            }

            SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
            {
                return false;
            }

            SBE_NODISCARD static std::size_t computeLength(std::size_t filterLength = 0)
            {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
                std::size_t length = sbeBlockLength();

                length += filterHeaderLength();
                if (filterLength > 254LL)
                {
                    throw std::runtime_error("filterLength too long for length type [E109]");
                }
                length += filterLength;

                return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
            }
        };

private:
        Filters m_filters;

public:
        SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t filtersId() SBE_NOEXCEPT
        {
            return 100;
        }

        SBE_NODISCARD inline Filters &filters()
        {
            m_filters.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_filters;
        }

        Filters &filtersCount(const std::uint32_t count)
        {
            m_filters.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_filters;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t filtersSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool filtersInActingVersion() const SBE_NOEXCEPT
        {
            return true;
        }

        class Permissions
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
            Permissions() = default;

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
                dimensions.blockLength(static_cast<std::uint16_t>(0));
                dimensions.numInGroup(static_cast<std::uint32_t>(count));
                m_index = 0;
                m_count = count;
                m_blockLength = 0;
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
                return 0;
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

            inline Permissions &next()
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


            SBE_NODISCARD static const char *permissionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
            {
                switch (metaAttribute)
                {
                    case MetaAttribute::PRESENCE: return "required";
                    default: return "";
                }
            }

            static const char *permissionCharacterEncoding() SBE_NOEXCEPT
            {
                return "UTF-8";
            }

            static SBE_CONSTEXPR std::uint64_t permissionSinceVersion() SBE_NOEXCEPT
            {
                return 0;
            }

            bool permissionInActingVersion() SBE_NOEXCEPT
            {
                return true;
            }

            static SBE_CONSTEXPR std::uint16_t permissionId() SBE_NOEXCEPT
            {
                return 200;
            }

            static SBE_CONSTEXPR std::uint64_t permissionHeaderLength() SBE_NOEXCEPT
            {
                return 1;
            }

            SBE_NODISCARD std::uint8_t permissionLength() const
            {
                std::uint8_t length;
                std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
                return (length);
            }

            std::uint64_t skipPermission()
            {
                std::uint64_t lengthOfLengthField = 1;
                std::uint64_t lengthPosition = sbePosition();
                std::uint8_t lengthFieldValue;
                std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
                std::uint64_t dataLength = (lengthFieldValue);
                sbePosition(lengthPosition + lengthOfLengthField + dataLength);
                return dataLength;
            }

            SBE_NODISCARD const char *permission()
            {
                std::uint8_t lengthFieldValue;
                std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
                const char *fieldPtr = m_buffer + sbePosition() + 1;
                sbePosition(sbePosition() + 1 + (lengthFieldValue));
                return fieldPtr;
            }

            std::uint64_t getPermission(char *dst, const std::uint64_t length)
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

            Permissions &putPermission(const char *src, const std::uint8_t length)
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

            std::string getPermissionAsString()
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

            std::string getPermissionAsJsonEscapedString()
            {
                std::ostringstream oss;
                std::string s = getPermissionAsString();

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
            std::string_view getPermissionAsStringView()
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

            Permissions &putPermission(const std::string &str)
            {
                if (str.length() > 254)
                {
                    throw std::runtime_error("std::string too long for length type [E109]");
                }
                return putPermission(str.data(), static_cast<std::uint8_t>(str.length()));
            }

            #if __cplusplus >= 201703L
            Permissions &putPermission(const std::string_view str)
            {
                if (str.length() > 254)
                {
                    throw std::runtime_error("std::string too long for length type [E109]");
                }
                return putPermission(str.data(), static_cast<std::uint8_t>(str.length()));
            }
            #endif

            template<typename CharT, typename Traits>
            friend std::basic_ostream<CharT, Traits> & operator << (
                std::basic_ostream<CharT, Traits> &builder, Permissions &writer)
            {
                builder << '{';
                builder << R"("permission": )";
                builder << '"' <<
                    writer.getPermissionAsJsonEscapedString().c_str() << '"';

                builder << '}';

                return builder;
            }

            void skip()
            {
                skipPermission();
            }

            SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
            {
                return false;
            }

            SBE_NODISCARD static std::size_t computeLength(std::size_t permissionLength = 0)
            {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
                std::size_t length = sbeBlockLength();

                length += permissionHeaderLength();
                if (permissionLength > 254LL)
                {
                    throw std::runtime_error("permissionLength too long for length type [E109]");
                }
                length += permissionLength;

                return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
            }
        };

private:
        Permissions m_permissions;

public:
        SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t permissionsId() SBE_NOEXCEPT
        {
            return 101;
        }

        SBE_NODISCARD inline Permissions &permissions()
        {
            m_permissions.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_permissions;
        }

        Permissions &permissionsCount(const std::uint32_t count)
        {
            m_permissions.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_permissions;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t permissionsSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool permissionsInActingVersion() const SBE_NOEXCEPT
        {
            return true;
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

        Symbols &putSymbol(const char *src, const std::uint8_t length)
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

        Symbols &putSymbol(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Symbols &putSymbol(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        SBE_NODISCARD static const char *baseAssetMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *baseAssetCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t baseAssetSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool baseAssetInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t baseAssetId() SBE_NOEXCEPT
        {
            return 201;
        }

        static SBE_CONSTEXPR std::uint64_t baseAssetHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t baseAssetLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipBaseAsset()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *baseAsset()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getBaseAsset(char *dst, const std::uint64_t length)
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

        Symbols &putBaseAsset(const char *src, const std::uint8_t length)
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

        std::string getBaseAssetAsString()
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

        std::string getBaseAssetAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getBaseAssetAsString();

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
        std::string_view getBaseAssetAsStringView()
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

        Symbols &putBaseAsset(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putBaseAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Symbols &putBaseAsset(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putBaseAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        SBE_NODISCARD static const char *quoteAssetMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *quoteAssetCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t quoteAssetSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool quoteAssetInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t quoteAssetId() SBE_NOEXCEPT
        {
            return 202;
        }

        static SBE_CONSTEXPR std::uint64_t quoteAssetHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t quoteAssetLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipQuoteAsset()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *quoteAsset()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getQuoteAsset(char *dst, const std::uint64_t length)
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

        Symbols &putQuoteAsset(const char *src, const std::uint8_t length)
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

        std::string getQuoteAssetAsString()
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

        std::string getQuoteAssetAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getQuoteAssetAsString();

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
        std::string_view getQuoteAssetAsStringView()
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

        Symbols &putQuoteAsset(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putQuoteAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Symbols &putQuoteAsset(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putQuoteAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, Symbols &writer)
        {
            builder << '{';
            builder << R"("status": )";
            builder << '"' << writer.status() << '"';

            builder << ", ";
            builder << R"("baseAssetPrecision": )";
            builder << +writer.baseAssetPrecision();

            builder << ", ";
            builder << R"("quoteAssetPrecision": )";
            builder << +writer.quoteAssetPrecision();

            builder << ", ";
            builder << R"("baseCommissionPrecision": )";
            builder << +writer.baseCommissionPrecision();

            builder << ", ";
            builder << R"("quoteCommissionPrecision": )";
            builder << +writer.quoteCommissionPrecision();

            builder << ", ";
            builder << R"("orderTypes": )";
            builder << writer.orderTypes();

            builder << ", ";
            builder << R"("icebergAllowed": )";
            builder << '"' << writer.icebergAllowed() << '"';

            builder << ", ";
            builder << R"("ocoAllowed": )";
            builder << '"' << writer.ocoAllowed() << '"';

            builder << ", ";
            builder << R"("quoteOrderQtyMarketAllowed": )";
            builder << '"' << writer.quoteOrderQtyMarketAllowed() << '"';

            builder << ", ";
            builder << R"("allowTrailingStop": )";
            builder << '"' << writer.allowTrailingStop() << '"';

            builder << ", ";
            builder << R"("cancelReplaceAllowed": )";
            builder << '"' << writer.cancelReplaceAllowed() << '"';

            builder << ", ";
            builder << R"("isSpotTradingAllowed": )";
            builder << '"' << writer.isSpotTradingAllowed() << '"';

            builder << ", ";
            builder << R"("isMarginTradingAllowed": )";
            builder << '"' << writer.isMarginTradingAllowed() << '"';

            builder << ", ";
            builder << R"("defaultSelfTradePreventionMode": )";
            builder << '"' << writer.defaultSelfTradePreventionMode() << '"';

            builder << ", ";
            builder << R"("allowedSelfTradePreventionModes": )";
            builder << writer.allowedSelfTradePreventionModes();

            builder << ", ";
            {
                bool atLeastOne = false;
                builder << R"("filters": [)";
                writer.filters().forEach(
                    [&](Filters &filters)
                    {
                        if (atLeastOne)
                        {
                            builder << ", ";
                        }
                        atLeastOne = true;
                        builder << filters;
                    });
                builder << ']';
            }

            builder << ", ";
            {
                bool atLeastOne = false;
                builder << R"("permissions": [)";
                writer.permissions().forEach(
                    [&](Permissions &permissions)
                    {
                        if (atLeastOne)
                        {
                            builder << ", ";
                        }
                        atLeastOne = true;
                        builder << permissions;
                    });
                builder << ']';
            }

            builder << ", ";
            builder << R"("symbol": )";
            builder << '"' <<
                writer.getSymbolAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("baseAsset": )";
            builder << '"' <<
                writer.getBaseAssetAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("quoteAsset": )";
            builder << '"' <<
                writer.getQuoteAssetAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
            auto &filtersGroup { filters() };
            while (filtersGroup.hasNext())
            {
                filtersGroup.next().skip();
            }
            auto &permissionsGroup { permissions() };
            while (permissionsGroup.hasNext())
            {
                permissionsGroup.next().skip();
            }
            skipSymbol();
            skipBaseAsset();
            skipQuoteAsset();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(
            const std::vector<std::tuple<std::size_t>> &filtersItemLengths = {},
            const std::vector<std::tuple<std::size_t>> &permissionsItemLengths = {},
            std::size_t symbolLength = 0,
            std::size_t baseAssetLength = 0,
            std::size_t quoteAssetLength = 0)
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            length += Filters::sbeHeaderSize();
            if (filtersItemLengths.size() > 2147483647LL)
            {
                throw std::runtime_error("filtersItemLengths.size() outside of allowed range [E110]");
            }

            for (const auto &e: filtersItemLengths)
            {
                #if __cplusplus >= 201703L
                length += std::apply(Filters::computeLength, e);
                #else
                length += Filters::computeLength(std::get<0>(e));
                #endif
            }

            length += Permissions::sbeHeaderSize();
            if (permissionsItemLengths.size() > 2147483647LL)
            {
                throw std::runtime_error("permissionsItemLengths.size() outside of allowed range [E110]");
            }

            for (const auto &e: permissionsItemLengths)
            {
                #if __cplusplus >= 201703L
                length += std::apply(Permissions::computeLength, e);
                #else
                length += Permissions::computeLength(std::get<0>(e));
                #endif
            }

            length += symbolHeaderLength();
            if (symbolLength > 254LL)
            {
                throw std::runtime_error("symbolLength too long for length type [E109]");
            }
            length += symbolLength;

            length += baseAssetHeaderLength();
            if (baseAssetLength > 254LL)
            {
                throw std::runtime_error("baseAssetLength too long for length type [E109]");
            }
            length += baseAssetLength;

            length += quoteAssetHeaderLength();
            if (quoteAssetLength > 254LL)
            {
                throw std::runtime_error("quoteAssetLength too long for length type [E109]");
            }
            length += quoteAssetLength;

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    Symbols m_symbols;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t symbolsId() SBE_NOEXCEPT
    {
        return 102;
    }

    SBE_NODISCARD inline Symbols &symbols()
    {
        m_symbols.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_symbols;
    }

    Symbols &symbolsCount(const std::uint32_t count)
    {
        m_symbols.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_symbols;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t symbolsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool symbolsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class Sors
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
        Sors() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(0));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 0;
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
            return 0;
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

        inline Sors &next()
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


        class SorSymbols
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
            SorSymbols() = default;

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
                dimensions.blockLength(static_cast<std::uint16_t>(0));
                dimensions.numInGroup(static_cast<std::uint32_t>(count));
                m_index = 0;
                m_count = count;
                m_blockLength = 0;
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
                return 0;
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

            inline SorSymbols &next()
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

            SorSymbols &putSymbol(const char *src, const std::uint8_t length)
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

            SorSymbols &putSymbol(const std::string &str)
            {
                if (str.length() > 254)
                {
                    throw std::runtime_error("std::string too long for length type [E109]");
                }
                return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
            }

            #if __cplusplus >= 201703L
            SorSymbols &putSymbol(const std::string_view str)
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
                std::basic_ostream<CharT, Traits> &builder, SorSymbols &writer)
            {
                builder << '{';
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
        SorSymbols m_sorSymbols;

public:
        SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sorSymbolsId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD inline SorSymbols &sorSymbols()
        {
            m_sorSymbols.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_sorSymbols;
        }

        SorSymbols &sorSymbolsCount(const std::uint32_t count)
        {
            m_sorSymbols.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
            return m_sorSymbols;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sorSymbolsSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool sorSymbolsInActingVersion() const SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static const char *baseAssetMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *baseAssetCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t baseAssetSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool baseAssetInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t baseAssetId() SBE_NOEXCEPT
        {
            return 200;
        }

        static SBE_CONSTEXPR std::uint64_t baseAssetHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t baseAssetLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipBaseAsset()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *baseAsset()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getBaseAsset(char *dst, const std::uint64_t length)
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

        Sors &putBaseAsset(const char *src, const std::uint8_t length)
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

        std::string getBaseAssetAsString()
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

        std::string getBaseAssetAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getBaseAssetAsString();

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
        std::string_view getBaseAssetAsStringView()
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

        Sors &putBaseAsset(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putBaseAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Sors &putBaseAsset(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putBaseAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, Sors &writer)
        {
            builder << '{';
            {
                bool atLeastOne = false;
                builder << R"("sorSymbols": [)";
                writer.sorSymbols().forEach(
                    [&](SorSymbols &sorSymbols)
                    {
                        if (atLeastOne)
                        {
                            builder << ", ";
                        }
                        atLeastOne = true;
                        builder << sorSymbols;
                    });
                builder << ']';
            }

            builder << ", ";
            builder << R"("baseAsset": )";
            builder << '"' <<
                writer.getBaseAssetAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
            auto &sorSymbolsGroup { sorSymbols() };
            while (sorSymbolsGroup.hasNext())
            {
                sorSymbolsGroup.next().skip();
            }
            skipBaseAsset();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(
            const std::vector<std::tuple<std::size_t>> &sorSymbolsItemLengths = {},
            std::size_t baseAssetLength = 0)
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            length += SorSymbols::sbeHeaderSize();
            if (sorSymbolsItemLengths.size() > 2147483647LL)
            {
                throw std::runtime_error("sorSymbolsItemLengths.size() outside of allowed range [E110]");
            }

            for (const auto &e: sorSymbolsItemLengths)
            {
                #if __cplusplus >= 201703L
                length += std::apply(SorSymbols::computeLength, e);
                #else
                length += SorSymbols::computeLength(std::get<0>(e));
                #endif
            }

            length += baseAssetHeaderLength();
            if (baseAssetLength > 254LL)
            {
                throw std::runtime_error("baseAssetLength too long for length type [E109]");
            }
            length += baseAssetLength;

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    Sors m_sors;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sorsId() SBE_NOEXCEPT
    {
        return 103;
    }

    SBE_NODISCARD inline Sors &sors()
    {
        m_sors.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_sors;
    }

    Sors &sorsCount(const std::uint32_t count)
    {
        m_sors.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_sors;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sorsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sorsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const ExchangeInfoResponse &_writer)
{
    ExchangeInfoResponse writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "ExchangeInfoResponse", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    {
        bool atLeastOne = false;
        builder << R"("rateLimits": [)";
        writer.rateLimits().forEach(
            [&](RateLimits &rateLimits)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << rateLimits;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("exchangeFilters": [)";
        writer.exchangeFilters().forEach(
            [&](ExchangeFilters &exchangeFilters)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << exchangeFilters;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("symbols": [)";
        writer.symbols().forEach(
            [&](Symbols &symbols)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << symbols;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("sors": [)";
        writer.sors().forEach(
            [&](Sors &sors)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << sors;
            });
        builder << ']';
    }

    builder << '}';

    return builder;
}

void skip()
{
    auto &rateLimitsGroup { rateLimits() };
    while (rateLimitsGroup.hasNext())
    {
        rateLimitsGroup.next().skip();
    }
    auto &exchangeFiltersGroup { exchangeFilters() };
    while (exchangeFiltersGroup.hasNext())
    {
        exchangeFiltersGroup.next().skip();
    }
    auto &symbolsGroup { symbols() };
    while (symbolsGroup.hasNext())
    {
        symbolsGroup.next().skip();
    }
    auto &sorsGroup { sors() };
    while (sorsGroup.hasNext())
    {
        sorsGroup.next().skip();
    }
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    std::size_t rateLimitsLength = 0,
    const std::vector<std::tuple<std::size_t>> &exchangeFiltersItemLengths = {},
    const std::vector<std::tuple<
        const std::vector<std::tuple<std::size_t>> &,
        const std::vector<std::tuple<std::size_t>> &,
        std::size_t,
        std::size_t,
        std::size_t>> &symbolsItemLengths = {},
    const std::vector<std::tuple<
        const std::vector<std::tuple<std::size_t>> &,
        std::size_t>> &sorsItemLengths = {})
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += RateLimits::sbeHeaderSize();
    if (rateLimitsLength > 2147483647LL)
    {
        throw std::runtime_error("rateLimitsLength outside of allowed range [E110]");
    }
    length += rateLimitsLength *RateLimits::sbeBlockLength();

    length += ExchangeFilters::sbeHeaderSize();
    if (exchangeFiltersItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("exchangeFiltersItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: exchangeFiltersItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(ExchangeFilters::computeLength, e);
        #else
        length += ExchangeFilters::computeLength(std::get<0>(e));
        #endif
    }

    length += Symbols::sbeHeaderSize();
    if (symbolsItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("symbolsItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: symbolsItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(Symbols::computeLength, e);
        #else
        length += Symbols::computeLength(std::get<0>(e), std::get<1>(e), std::get<2>(e), std::get<3>(e), std::get<4>(e));
        #endif
    }

    length += Sors::sbeHeaderSize();
    if (sorsItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("sorsItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: sorsItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(Sors::computeLength, e);
        #else
        length += Sors::computeLength(std::get<0>(e), std::get<1>(e));
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
