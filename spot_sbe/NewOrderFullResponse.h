/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_NEWORDERFULLRESPONSE_CXX_H_
#define _SPOT_SBE_NEWORDERFULLRESPONSE_CXX_H_

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

class NewOrderFullResponse
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
    static const std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(134);
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(302);
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

    NewOrderFullResponse() = default;

    NewOrderFullResponse(
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

    NewOrderFullResponse(char *buffer, const std::uint64_t bufferLength) :
        NewOrderFullResponse(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    NewOrderFullResponse(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        NewOrderFullResponse(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(134);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(302);
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

    NewOrderFullResponse &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    NewOrderFullResponse &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
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

    NewOrderFullResponse &wrapForDecode(
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

    NewOrderFullResponse &sbeRewind()
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
        NewOrderFullResponse skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
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

    NewOrderFullResponse &priceExponent(const std::int8_t value) SBE_NOEXCEPT
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

    NewOrderFullResponse &qtyExponent(const std::int8_t value) SBE_NOEXCEPT
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::int8_t));
        return *this;
    }

    SBE_NODISCARD static const char *orderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t orderIdId() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t orderIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool orderIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderIdEncodingOffset() SBE_NOEXCEPT
    {
        return 2;
    }

    static SBE_CONSTEXPR std::int64_t orderIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t orderIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t orderIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t orderIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t orderId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &orderId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *orderListIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t orderListIdId() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t orderListIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool orderListIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderListIdEncodingOffset() SBE_NOEXCEPT
    {
        return 10;
    }

    static SBE_CONSTEXPR std::int64_t orderListIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t orderListIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t orderListIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t orderListIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t orderListId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &orderListId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 10, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *transactTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t transactTimeId() SBE_NOEXCEPT
    {
        return 5;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t transactTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool transactTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t transactTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 18;
    }

    static SBE_CONSTEXPR std::int64_t transactTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t transactTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t transactTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t transactTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t transactTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 18, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &transactTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 18, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *priceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t priceId() SBE_NOEXCEPT
    {
        return 6;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool priceInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceEncodingOffset() SBE_NOEXCEPT
    {
        return 26;
    }

    static SBE_CONSTEXPR std::int64_t priceNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t priceMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t priceMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t priceEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t price() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 26, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &price(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 26, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *origQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t origQtyId() SBE_NOEXCEPT
    {
        return 7;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t origQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool origQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t origQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 34;
    }

    static SBE_CONSTEXPR std::int64_t origQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t origQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t origQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t origQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t origQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 34, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &origQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 34, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *executedQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t executedQtyId() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t executedQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool executedQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t executedQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 42;
    }

    static SBE_CONSTEXPR std::int64_t executedQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t executedQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t executedQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t executedQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t executedQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 42, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &executedQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 42, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *cummulativeQuoteQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t cummulativeQuoteQtyId() SBE_NOEXCEPT
    {
        return 9;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t cummulativeQuoteQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool cummulativeQuoteQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t cummulativeQuoteQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 50;
    }

    static SBE_CONSTEXPR std::int64_t cummulativeQuoteQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t cummulativeQuoteQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t cummulativeQuoteQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t cummulativeQuoteQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t cummulativeQuoteQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 50, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &cummulativeQuoteQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 50, &val, sizeof(std::int64_t));
        return *this;
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
        return 10;
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
        return 58;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t statusEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t statusRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 58, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD OrderStatus::Value status() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 58, sizeof(std::uint8_t));
        return OrderStatus::get((val));
    }

    NewOrderFullResponse &status(const OrderStatus::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 58, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *timeInForceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t timeInForceId() SBE_NOEXCEPT
    {
        return 11;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t timeInForceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool timeInForceInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t timeInForceEncodingOffset() SBE_NOEXCEPT
    {
        return 59;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t timeInForceEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t timeInForceRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 59, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD TimeInForce::Value timeInForce() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 59, sizeof(std::uint8_t));
        return TimeInForce::get((val));
    }

    NewOrderFullResponse &timeInForce(const TimeInForce::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 59, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *orderTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t orderTypeId() SBE_NOEXCEPT
    {
        return 12;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t orderTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool orderTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 60;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t orderTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 60, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD OrderType::Value orderType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 60, sizeof(std::uint8_t));
        return OrderType::get((val));
    }

    NewOrderFullResponse &orderType(const OrderType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 60, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *sideMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sideId() SBE_NOEXCEPT
    {
        return 13;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sideSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sideInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sideEncodingOffset() SBE_NOEXCEPT
    {
        return 61;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sideEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t sideRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 61, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD OrderSide::Value side() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 61, sizeof(std::uint8_t));
        return OrderSide::get((val));
    }

    NewOrderFullResponse &side(const OrderSide::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 61, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *stopPriceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t stopPriceId() SBE_NOEXCEPT
    {
        return 14;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t stopPriceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool stopPriceInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t stopPriceEncodingOffset() SBE_NOEXCEPT
    {
        return 62;
    }

    static SBE_CONSTEXPR std::int64_t stopPriceNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t stopPriceMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t stopPriceMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t stopPriceEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t stopPrice() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 62, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &stopPrice(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 62, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *trailingDeltaMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t trailingDeltaId() SBE_NOEXCEPT
    {
        return 15;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t trailingDeltaSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool trailingDeltaInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t trailingDeltaEncodingOffset() SBE_NOEXCEPT
    {
        return 70;
    }

    static SBE_CONSTEXPR std::int64_t trailingDeltaNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t trailingDeltaMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t trailingDeltaMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t trailingDeltaEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t trailingDelta() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 70, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &trailingDelta(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 70, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *trailingTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t trailingTimeId() SBE_NOEXCEPT
    {
        return 16;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t trailingTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool trailingTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t trailingTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 78;
    }

    static SBE_CONSTEXPR std::int64_t trailingTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t trailingTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t trailingTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t trailingTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t trailingTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 78, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &trailingTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 78, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *workingTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t workingTimeId() SBE_NOEXCEPT
    {
        return 17;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t workingTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool workingTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t workingTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 86;
    }

    static SBE_CONSTEXPR std::int64_t workingTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t workingTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t workingTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t workingTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t workingTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 86, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &workingTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 86, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *icebergQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t icebergQtyId() SBE_NOEXCEPT
    {
        return 18;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t icebergQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool icebergQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t icebergQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 94;
    }

    static SBE_CONSTEXPR std::int64_t icebergQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t icebergQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t icebergQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t icebergQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t icebergQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 94, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &icebergQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 94, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *strategyIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t strategyIdId() SBE_NOEXCEPT
    {
        return 19;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t strategyIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool strategyIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t strategyIdEncodingOffset() SBE_NOEXCEPT
    {
        return 102;
    }

    static SBE_CONSTEXPR std::int64_t strategyIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t strategyIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t strategyIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t strategyIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t strategyId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 102, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &strategyId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 102, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *strategyTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t strategyTypeId() SBE_NOEXCEPT
    {
        return 20;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t strategyTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool strategyTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t strategyTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 110;
    }

    static SBE_CONSTEXPR std::int32_t strategyTypeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT32;
    }

    static SBE_CONSTEXPR std::int32_t strategyTypeMinValue() SBE_NOEXCEPT
    {
        return INT32_C(-2147483647);
    }

    static SBE_CONSTEXPR std::int32_t strategyTypeMaxValue() SBE_NOEXCEPT
    {
        return INT32_C(2147483647);
    }

    static SBE_CONSTEXPR std::size_t strategyTypeEncodingLength() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD std::int32_t strategyType() const SBE_NOEXCEPT
    {
        std::int32_t val;
        std::memcpy(&val, m_buffer + m_offset + 110, sizeof(std::int32_t));
        return SBE_LITTLE_ENDIAN_ENCODE_32(val);
    }

    NewOrderFullResponse &strategyType(const std::int32_t value) SBE_NOEXCEPT
    {
        std::int32_t val = SBE_LITTLE_ENDIAN_ENCODE_32(value);
        std::memcpy(m_buffer + m_offset + 110, &val, sizeof(std::int32_t));
        return *this;
    }

    SBE_NODISCARD static const char *orderCapacityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t orderCapacityId() SBE_NOEXCEPT
    {
        return 21;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t orderCapacitySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool orderCapacityInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderCapacityEncodingOffset() SBE_NOEXCEPT
    {
        return 114;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t orderCapacityEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t orderCapacityRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 114, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD OrderCapacity::Value orderCapacity() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 114, sizeof(std::uint8_t));
        return OrderCapacity::get((val));
    }

    NewOrderFullResponse &orderCapacity(const OrderCapacity::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 114, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *workingFloorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t workingFloorId() SBE_NOEXCEPT
    {
        return 22;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t workingFloorSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool workingFloorInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t workingFloorEncodingOffset() SBE_NOEXCEPT
    {
        return 115;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t workingFloorEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t workingFloorRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 115, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD Floor::Value workingFloor() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 115, sizeof(std::uint8_t));
        return Floor::get((val));
    }

    NewOrderFullResponse &workingFloor(const Floor::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 115, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *selfTradePreventionModeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t selfTradePreventionModeId() SBE_NOEXCEPT
    {
        return 23;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t selfTradePreventionModeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool selfTradePreventionModeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t selfTradePreventionModeEncodingOffset() SBE_NOEXCEPT
    {
        return 116;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t selfTradePreventionModeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t selfTradePreventionModeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 116, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD SelfTradePreventionMode::Value selfTradePreventionMode() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 116, sizeof(std::uint8_t));
        return SelfTradePreventionMode::get((val));
    }

    NewOrderFullResponse &selfTradePreventionMode(const SelfTradePreventionMode::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 116, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *tradeGroupIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t tradeGroupIdId() SBE_NOEXCEPT
    {
        return 24;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tradeGroupIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool tradeGroupIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t tradeGroupIdEncodingOffset() SBE_NOEXCEPT
    {
        return 117;
    }

    static SBE_CONSTEXPR std::int64_t tradeGroupIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t tradeGroupIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t tradeGroupIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t tradeGroupIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t tradeGroupId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 117, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &tradeGroupId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 117, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *preventedQuantityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t preventedQuantityId() SBE_NOEXCEPT
    {
        return 25;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t preventedQuantitySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool preventedQuantityInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t preventedQuantityEncodingOffset() SBE_NOEXCEPT
    {
        return 125;
    }

    static SBE_CONSTEXPR std::int64_t preventedQuantityNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t preventedQuantityMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t preventedQuantityMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t preventedQuantityEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t preventedQuantity() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 125, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderFullResponse &preventedQuantity(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 125, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *usedSorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t usedSorId() SBE_NOEXCEPT
    {
        return 26;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t usedSorSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool usedSorInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t usedSorEncodingOffset() SBE_NOEXCEPT
    {
        return 133;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t usedSorEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t usedSorRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 133, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value usedSor() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 133, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    NewOrderFullResponse &usedSor(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 133, &val, sizeof(std::uint8_t));
        return *this;
    }

    class Fills
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
        Fills() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(42));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 42;
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
            return 42;
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

        inline Fills &next()
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


        SBE_NODISCARD static const char *commissionExponentMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t commissionExponentId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t commissionExponentSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool commissionExponentInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t commissionExponentEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::int8_t commissionExponentNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT8;
        }

        static SBE_CONSTEXPR std::int8_t commissionExponentMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(-127);
        }

        static SBE_CONSTEXPR std::int8_t commissionExponentMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(127);
        }

        static SBE_CONSTEXPR std::size_t commissionExponentEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::int8_t commissionExponent() const SBE_NOEXCEPT
        {
            std::int8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int8_t));
            return (val);
        }

        Fills &commissionExponent(const std::int8_t value) SBE_NOEXCEPT
        {
            std::int8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int8_t));
            return *this;
        }

        SBE_NODISCARD static const char *matchTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t matchTypeId() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t matchTypeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool matchTypeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t matchTypeEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t matchTypeEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t matchTypeRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD MatchType::Value matchType() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::uint8_t));
            return MatchType::get((val));
        }

        Fills &matchType(const MatchType::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *priceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t priceId() SBE_NOEXCEPT
        {
            return 3;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool priceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceEncodingOffset() SBE_NOEXCEPT
        {
            return 2;
        }

        static SBE_CONSTEXPR std::int64_t priceNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t priceMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t priceMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t priceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t price() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 2, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Fills &price(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 2, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *qtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t qtyId() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t qtySinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool qtyInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t qtyEncodingOffset() SBE_NOEXCEPT
        {
            return 10;
        }

        static SBE_CONSTEXPR std::int64_t qtyNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t qtyMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t qtyMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t qtyEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t qty() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Fills &qty(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 10, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *commissionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t commissionId() SBE_NOEXCEPT
        {
            return 5;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t commissionSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool commissionInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t commissionEncodingOffset() SBE_NOEXCEPT
        {
            return 18;
        }

        static SBE_CONSTEXPR std::int64_t commissionNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t commissionMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t commissionMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t commissionEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t commission() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 18, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Fills &commission(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 18, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *tradeIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t tradeIdId() SBE_NOEXCEPT
        {
            return 6;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tradeIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool tradeIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t tradeIdEncodingOffset() SBE_NOEXCEPT
        {
            return 26;
        }

        static SBE_CONSTEXPR std::int64_t tradeIdNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t tradeIdMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t tradeIdMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t tradeIdEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t tradeId() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 26, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Fills &tradeId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 26, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *allocIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t allocIdId() SBE_NOEXCEPT
        {
            return 7;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allocIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool allocIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocIdEncodingOffset() SBE_NOEXCEPT
        {
            return 34;
        }

        static SBE_CONSTEXPR std::int64_t allocIdNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t allocIdMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t allocIdMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t allocIdEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t allocId() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 34, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Fills &allocId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 34, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *commissionAssetMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *commissionAssetCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t commissionAssetSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool commissionAssetInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t commissionAssetId() SBE_NOEXCEPT
        {
            return 200;
        }

        static SBE_CONSTEXPR std::uint64_t commissionAssetHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t commissionAssetLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipCommissionAsset()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *commissionAsset()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getCommissionAsset(char *dst, const std::uint64_t length)
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

        Fills &putCommissionAsset(const char *src, const std::uint8_t length)
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

        std::string getCommissionAssetAsString()
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

        std::string getCommissionAssetAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getCommissionAssetAsString();

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
        std::string_view getCommissionAssetAsStringView()
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

        Fills &putCommissionAsset(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putCommissionAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Fills &putCommissionAsset(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putCommissionAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, Fills &writer)
        {
            builder << '{';
            builder << R"("commissionExponent": )";
            builder << +writer.commissionExponent();

            builder << ", ";
            builder << R"("matchType": )";
            builder << '"' << writer.matchType() << '"';

            builder << ", ";
            builder << R"("price": )";
            builder << +writer.price();

            builder << ", ";
            builder << R"("qty": )";
            builder << +writer.qty();

            builder << ", ";
            builder << R"("commission": )";
            builder << +writer.commission();

            builder << ", ";
            builder << R"("tradeId": )";
            builder << +writer.tradeId();

            builder << ", ";
            builder << R"("allocId": )";
            builder << +writer.allocId();

            builder << ", ";
            builder << R"("commissionAsset": )";
            builder << '"' <<
                writer.getCommissionAssetAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
            skipCommissionAsset();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(std::size_t commissionAssetLength = 0)
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            length += commissionAssetHeaderLength();
            if (commissionAssetLength > 254LL)
            {
                throw std::runtime_error("commissionAssetLength too long for length type [E109]");
            }
            length += commissionAssetLength;

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    Fills m_fills;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t fillsId() SBE_NOEXCEPT
    {
        return 100;
    }

    SBE_NODISCARD inline Fills &fills()
    {
        m_fills.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_fills;
    }

    Fills &fillsCount(const std::uint32_t count)
    {
        m_fills.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_fills;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t fillsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool fillsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class PreventedMatches
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
        PreventedMatches() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(40));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 40;
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
            return 40;
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

        inline PreventedMatches &next()
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


        SBE_NODISCARD static const char *preventedMatchIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t preventedMatchIdId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t preventedMatchIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool preventedMatchIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t preventedMatchIdEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::int64_t preventedMatchIdNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t preventedMatchIdMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t preventedMatchIdMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t preventedMatchIdEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t preventedMatchId() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        PreventedMatches &preventedMatchId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *makerOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t makerOrderIdId() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t makerOrderIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool makerOrderIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t makerOrderIdEncodingOffset() SBE_NOEXCEPT
        {
            return 8;
        }

        static SBE_CONSTEXPR std::int64_t makerOrderIdNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t makerOrderIdMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t makerOrderIdMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t makerOrderIdEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t makerOrderId() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        PreventedMatches &makerOrderId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *priceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t priceId() SBE_NOEXCEPT
        {
            return 3;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool priceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceEncodingOffset() SBE_NOEXCEPT
        {
            return 16;
        }

        static SBE_CONSTEXPR std::int64_t priceNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t priceMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t priceMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t priceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t price() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 16, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        PreventedMatches &price(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 16, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *takerPreventedQuantityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t takerPreventedQuantityId() SBE_NOEXCEPT
        {
            return 4;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t takerPreventedQuantitySinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool takerPreventedQuantityInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t takerPreventedQuantityEncodingOffset() SBE_NOEXCEPT
        {
            return 24;
        }

        static SBE_CONSTEXPR std::int64_t takerPreventedQuantityNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t takerPreventedQuantityMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t takerPreventedQuantityMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t takerPreventedQuantityEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t takerPreventedQuantity() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 24, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        PreventedMatches &takerPreventedQuantity(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 24, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *makerPreventedQuantityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "optional";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t makerPreventedQuantityId() SBE_NOEXCEPT
        {
            return 5;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t makerPreventedQuantitySinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool makerPreventedQuantityInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t makerPreventedQuantityEncodingOffset() SBE_NOEXCEPT
        {
            return 32;
        }

        static SBE_CONSTEXPR std::int64_t makerPreventedQuantityNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t makerPreventedQuantityMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t makerPreventedQuantityMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t makerPreventedQuantityEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t makerPreventedQuantity() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 32, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        PreventedMatches &makerPreventedQuantity(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 32, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *makerSymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static const char *makerSymbolCharacterEncoding() SBE_NOEXCEPT
        {
            return "UTF-8";
        }

        static SBE_CONSTEXPR std::uint64_t makerSymbolSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        bool makerSymbolInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        static SBE_CONSTEXPR std::uint16_t makerSymbolId() SBE_NOEXCEPT
        {
            return 200;
        }

        static SBE_CONSTEXPR std::uint64_t makerSymbolHeaderLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t makerSymbolLength() const
        {
            std::uint8_t length;
            std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
            return (length);
        }

        std::uint64_t skipMakerSymbol()
        {
            std::uint64_t lengthOfLengthField = 1;
            std::uint64_t lengthPosition = sbePosition();
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
            std::uint64_t dataLength = (lengthFieldValue);
            sbePosition(lengthPosition + lengthOfLengthField + dataLength);
            return dataLength;
        }

        SBE_NODISCARD const char *makerSymbol()
        {
            std::uint8_t lengthFieldValue;
            std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
            const char *fieldPtr = m_buffer + sbePosition() + 1;
            sbePosition(sbePosition() + 1 + (lengthFieldValue));
            return fieldPtr;
        }

        std::uint64_t getMakerSymbol(char *dst, const std::uint64_t length)
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

        PreventedMatches &putMakerSymbol(const char *src, const std::uint8_t length)
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

        std::string getMakerSymbolAsString()
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

        std::string getMakerSymbolAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getMakerSymbolAsString();

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
        std::string_view getMakerSymbolAsStringView()
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

        PreventedMatches &putMakerSymbol(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putMakerSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        PreventedMatches &putMakerSymbol(const std::string_view str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putMakerSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, PreventedMatches &writer)
        {
            builder << '{';
            builder << R"("preventedMatchId": )";
            builder << +writer.preventedMatchId();

            builder << ", ";
            builder << R"("makerOrderId": )";
            builder << +writer.makerOrderId();

            builder << ", ";
            builder << R"("price": )";
            builder << +writer.price();

            builder << ", ";
            builder << R"("takerPreventedQuantity": )";
            builder << +writer.takerPreventedQuantity();

            builder << ", ";
            builder << R"("makerPreventedQuantity": )";
            builder << +writer.makerPreventedQuantity();

            builder << ", ";
            builder << R"("makerSymbol": )";
            builder << '"' <<
                writer.getMakerSymbolAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
            skipMakerSymbol();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(std::size_t makerSymbolLength = 0)
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            length += makerSymbolHeaderLength();
            if (makerSymbolLength > 254LL)
            {
                throw std::runtime_error("makerSymbolLength too long for length type [E109]");
            }
            length += makerSymbolLength;

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    PreventedMatches m_preventedMatches;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t preventedMatchesId() SBE_NOEXCEPT
    {
        return 101;
    }

    SBE_NODISCARD inline PreventedMatches &preventedMatches()
    {
        m_preventedMatches.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_preventedMatches;
    }

    PreventedMatches &preventedMatchesCount(const std::uint32_t count)
    {
        m_preventedMatches.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_preventedMatches;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t preventedMatchesSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool preventedMatchesInActingVersion() const SBE_NOEXCEPT
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

    NewOrderFullResponse &putSymbol(const char *src, const std::uint8_t length)
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

    NewOrderFullResponse &putSymbol(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    NewOrderFullResponse &putSymbol(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

    SBE_NODISCARD static const char *clientOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *clientOrderIdCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t clientOrderIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool clientOrderIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    static SBE_CONSTEXPR std::uint16_t clientOrderIdId() SBE_NOEXCEPT
    {
        return 201;
    }

    static SBE_CONSTEXPR std::uint64_t clientOrderIdHeaderLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t clientOrderIdLength() const
    {
        std::uint8_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
        return (length);
    }

    std::uint64_t skipClientOrderId()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *clientOrderId()
    {
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
        const char *fieldPtr = m_buffer + sbePosition() + 1;
        sbePosition(sbePosition() + 1 + (lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getClientOrderId(char *dst, const std::uint64_t length)
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

    NewOrderFullResponse &putClientOrderId(const char *src, const std::uint8_t length)
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

    std::string getClientOrderIdAsString()
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

    std::string getClientOrderIdAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getClientOrderIdAsString();

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
    std::string_view getClientOrderIdAsStringView()
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

    NewOrderFullResponse &putClientOrderId(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putClientOrderId(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    NewOrderFullResponse &putClientOrderId(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putClientOrderId(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const NewOrderFullResponse &_writer)
{
    NewOrderFullResponse writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "NewOrderFullResponse", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("priceExponent": )";
    builder << +writer.priceExponent();

    builder << ", ";
    builder << R"("qtyExponent": )";
    builder << +writer.qtyExponent();

    builder << ", ";
    builder << R"("orderId": )";
    builder << +writer.orderId();

    builder << ", ";
    builder << R"("orderListId": )";
    builder << +writer.orderListId();

    builder << ", ";
    builder << R"("transactTime": )";
    builder << +writer.transactTime();

    builder << ", ";
    builder << R"("price": )";
    builder << +writer.price();

    builder << ", ";
    builder << R"("origQty": )";
    builder << +writer.origQty();

    builder << ", ";
    builder << R"("executedQty": )";
    builder << +writer.executedQty();

    builder << ", ";
    builder << R"("cummulativeQuoteQty": )";
    builder << +writer.cummulativeQuoteQty();

    builder << ", ";
    builder << R"("status": )";
    builder << '"' << writer.status() << '"';

    builder << ", ";
    builder << R"("timeInForce": )";
    builder << '"' << writer.timeInForce() << '"';

    builder << ", ";
    builder << R"("orderType": )";
    builder << '"' << writer.orderType() << '"';

    builder << ", ";
    builder << R"("side": )";
    builder << '"' << writer.side() << '"';

    builder << ", ";
    builder << R"("stopPrice": )";
    builder << +writer.stopPrice();

    builder << ", ";
    builder << R"("trailingDelta": )";
    builder << +writer.trailingDelta();

    builder << ", ";
    builder << R"("trailingTime": )";
    builder << +writer.trailingTime();

    builder << ", ";
    builder << R"("workingTime": )";
    builder << +writer.workingTime();

    builder << ", ";
    builder << R"("icebergQty": )";
    builder << +writer.icebergQty();

    builder << ", ";
    builder << R"("strategyId": )";
    builder << +writer.strategyId();

    builder << ", ";
    builder << R"("strategyType": )";
    builder << +writer.strategyType();

    builder << ", ";
    builder << R"("orderCapacity": )";
    builder << '"' << writer.orderCapacity() << '"';

    builder << ", ";
    builder << R"("workingFloor": )";
    builder << '"' << writer.workingFloor() << '"';

    builder << ", ";
    builder << R"("selfTradePreventionMode": )";
    builder << '"' << writer.selfTradePreventionMode() << '"';

    builder << ", ";
    builder << R"("tradeGroupId": )";
    builder << +writer.tradeGroupId();

    builder << ", ";
    builder << R"("preventedQuantity": )";
    builder << +writer.preventedQuantity();

    builder << ", ";
    builder << R"("usedSor": )";
    builder << '"' << writer.usedSor() << '"';

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("fills": [)";
        writer.fills().forEach(
            [&](Fills &fills)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << fills;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("preventedMatches": [)";
        writer.preventedMatches().forEach(
            [&](PreventedMatches &preventedMatches)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << preventedMatches;
            });
        builder << ']';
    }

    builder << ", ";
    builder << R"("symbol": )";
    builder << '"' <<
        writer.getSymbolAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("clientOrderId": )";
    builder << '"' <<
        writer.getClientOrderIdAsJsonEscapedString().c_str() << '"';

    builder << '}';

    return builder;
}

void skip()
{
    auto &fillsGroup { fills() };
    while (fillsGroup.hasNext())
    {
        fillsGroup.next().skip();
    }
    auto &preventedMatchesGroup { preventedMatches() };
    while (preventedMatchesGroup.hasNext())
    {
        preventedMatchesGroup.next().skip();
    }
    skipSymbol();
    skipClientOrderId();
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    const std::vector<std::tuple<std::size_t>> &fillsItemLengths = {},
    const std::vector<std::tuple<std::size_t>> &preventedMatchesItemLengths = {},
    std::size_t symbolLength = 0,
    std::size_t clientOrderIdLength = 0)
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += Fills::sbeHeaderSize();
    if (fillsItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("fillsItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: fillsItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(Fills::computeLength, e);
        #else
        length += Fills::computeLength(std::get<0>(e));
        #endif
    }

    length += PreventedMatches::sbeHeaderSize();
    if (preventedMatchesItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("preventedMatchesItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: preventedMatchesItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(PreventedMatches::computeLength, e);
        #else
        length += PreventedMatches::computeLength(std::get<0>(e));
        #endif
    }

    length += symbolHeaderLength();
    if (symbolLength > 254LL)
    {
        throw std::runtime_error("symbolLength too long for length type [E109]");
    }
    length += symbolLength;

    length += clientOrderIdHeaderLength();
    if (clientOrderIdLength > 254LL)
    {
        throw std::runtime_error("clientOrderIdLength too long for length type [E109]");
    }
    length += clientOrderIdLength;

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
