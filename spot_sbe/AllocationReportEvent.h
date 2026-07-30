/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_ALLOCATIONREPORTEVENT_CXX_H_
#define _SPOT_SBE_ALLOCATIONREPORTEVENT_CXX_H_

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
#  if !defined(SBE_USE_STRING_VIEW)
#    define SBE_USE_STRING_VIEW 1
#  endif
#else
#  define SBE_NODISCARD
#endif

#if __cplusplus >= 202002L
#  include <span>
#  if !defined(SBE_USE_SPAN)
#    define SBE_USE_SPAN 1
#  endif
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


#include "CounterPartyRole.h"
#include "CalculationType.h"
#include "OrderType.h"
#include "VarString.h"
#include "MatchType.h"
#include "ExecutionType.h"
#include "BoolEnum.h"
#include "OrderStatus.h"
#include "ExecutionRuleType.h"
#include "GroupSizeEncoding.h"
#include "PegPriceType.h"
#include "GroupSize16Encoding.h"
#include "OptionalMessageData.h"
#include "ContingencyType.h"
#include "ListOrderStatus.h"
#include "MessageData8.h"
#include "RateLimitInterval.h"
#include "Floor.h"
#include "TimeInForce.h"
#include "ListStatusType.h"
#include "AllocationStatus.h"
#include "AllowedSelfTradePreventionModes.h"
#include "MessageHeader.h"
#include "AllocationReportType.h"
#include "AccountType.h"
#include "ExpiryReason.h"
#include "AllocationTransactionType.h"
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
#include "PegOffsetType.h"
#include "VarString8.h"
#include "MessageData.h"

namespace spot_sbe {

class AllocationReportEvent
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
    static constexpr std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(122);
    static constexpr std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(600);
    static constexpr std::uint16_t SBE_SCHEMA_ID = static_cast<std::uint16_t>(3);
    static constexpr std::uint16_t SBE_SCHEMA_VERSION = static_cast<std::uint16_t>(5);
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

    AllocationReportEvent() = default;

    AllocationReportEvent(
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

    AllocationReportEvent(char *buffer, const std::uint64_t bufferLength) :
        AllocationReportEvent(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    AllocationReportEvent(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        AllocationReportEvent(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(122);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(600);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(3);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(5);
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

    AllocationReportEvent &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    AllocationReportEvent &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
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

    AllocationReportEvent &wrapForDecode(
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

    AllocationReportEvent &sbeRewind()
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
        AllocationReportEvent skipper(m_buffer, m_offset, m_bufferLength, m_actingBlockLength, m_actingVersion);
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

    SBE_NODISCARD static const char *eventTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t eventTimeId() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t eventTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool eventTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t eventTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR std::int64_t eventTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t eventTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t eventTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t eventTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t eventTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &eventTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int64_t));
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
        return 2;
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
        return 8;
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
        std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &transactTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::int64_t));
        return *this;
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
        return 3;
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
        return 16;
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
        std::memcpy(&val, m_buffer + m_offset + 16, sizeof(std::int8_t));
        return (val);
    }

    AllocationReportEvent &priceExponent(const std::int8_t value) SBE_NOEXCEPT
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 16, &val, sizeof(std::int8_t));
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
        return 4;
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
        return 17;
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
        std::memcpy(&val, m_buffer + m_offset + 17, sizeof(std::int8_t));
        return (val);
    }

    AllocationReportEvent &qtyExponent(const std::int8_t value) SBE_NOEXCEPT
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 17, &val, sizeof(std::int8_t));
        return *this;
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
        return 5;
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
        return 18;
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
        std::memcpy(&val, m_buffer + m_offset + 18, sizeof(std::int8_t));
        return (val);
    }

    AllocationReportEvent &commissionExponent(const std::int8_t value) SBE_NOEXCEPT
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 18, &val, sizeof(std::int8_t));
        return *this;
    }

    SBE_NODISCARD static const char *allocationTransactionTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t allocationTransactionTypeId() SBE_NOEXCEPT
    {
        return 6;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allocationTransactionTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool allocationTransactionTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationTransactionTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 19;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationTransactionTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t allocationTransactionTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 19, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD AllocationTransactionType::Value allocationTransactionType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 19, sizeof(std::uint8_t));
        return AllocationTransactionType::get((val));
    }

    AllocationReportEvent &allocationTransactionType(const AllocationTransactionType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 19, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *allocationReportTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t allocationReportTypeId() SBE_NOEXCEPT
    {
        return 7;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allocationReportTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool allocationReportTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationReportTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 20;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationReportTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t allocationReportTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 20, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD AllocationReportType::Value allocationReportType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 20, sizeof(std::uint8_t));
        return AllocationReportType::get((val));
    }

    AllocationReportEvent &allocationReportType(const AllocationReportType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 20, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *allocationStatusMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t allocationStatusId() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allocationStatusSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool allocationStatusInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationStatusEncodingOffset() SBE_NOEXCEPT
    {
        return 21;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationStatusEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t allocationStatusRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 21, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD AllocationStatus::Value allocationStatus() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 21, sizeof(std::uint8_t));
        return AllocationStatus::get((val));
    }

    AllocationReportEvent &allocationStatus(const AllocationStatus::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 21, &val, sizeof(std::uint8_t));
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
        return 9;
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
        return 22;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sideEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t sideRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 22, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD OrderSide::Value side() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 22, sizeof(std::uint8_t));
        return OrderSide::get((val));
    }

    AllocationReportEvent &side(const OrderSide::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 22, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *counterPartyRoleMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t counterPartyRoleId() SBE_NOEXCEPT
    {
        return 10;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t counterPartyRoleSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool counterPartyRoleInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t counterPartyRoleEncodingOffset() SBE_NOEXCEPT
    {
        return 23;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t counterPartyRoleEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t counterPartyRoleRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 23, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD CounterPartyRole::Value counterPartyRole() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 23, sizeof(std::uint8_t));
        return CounterPartyRole::get((val));
    }

    AllocationReportEvent &counterPartyRole(const CounterPartyRole::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 23, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *counterPartyExternalAccountIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t counterPartyExternalAccountIdId() SBE_NOEXCEPT
    {
        return 11;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t counterPartyExternalAccountIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool counterPartyExternalAccountIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t counterPartyExternalAccountIdEncodingOffset() SBE_NOEXCEPT
    {
        return 24;
    }

    static SBE_CONSTEXPR std::int64_t counterPartyExternalAccountIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t counterPartyExternalAccountIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t counterPartyExternalAccountIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t counterPartyExternalAccountIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t counterPartyExternalAccountId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 24, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &counterPartyExternalAccountId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 24, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *counterPartyOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t counterPartyOrderIdId() SBE_NOEXCEPT
    {
        return 12;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t counterPartyOrderIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool counterPartyOrderIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t counterPartyOrderIdEncodingOffset() SBE_NOEXCEPT
    {
        return 32;
    }

    static SBE_CONSTEXPR std::int64_t counterPartyOrderIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t counterPartyOrderIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t counterPartyOrderIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t counterPartyOrderIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t counterPartyOrderId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 32, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &counterPartyOrderId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 32, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *allocationReportIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t allocationReportIdId() SBE_NOEXCEPT
    {
        return 13;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allocationReportIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool allocationReportIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationReportIdEncodingOffset() SBE_NOEXCEPT
    {
        return 40;
    }

    static SBE_CONSTEXPR std::int64_t allocationReportIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t allocationReportIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t allocationReportIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t allocationReportIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t allocationReportId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 40, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &allocationReportId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 40, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *allocationIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t allocationIdId() SBE_NOEXCEPT
    {
        return 14;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t allocationIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool allocationIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t allocationIdEncodingOffset() SBE_NOEXCEPT
    {
        return 48;
    }

    static SBE_CONSTEXPR std::int64_t allocationIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t allocationIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t allocationIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t allocationIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t allocationId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 48, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &allocationId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 48, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *sourceOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceOrderIdId() SBE_NOEXCEPT
    {
        return 15;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceOrderIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceOrderIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceOrderIdEncodingOffset() SBE_NOEXCEPT
    {
        return 56;
    }

    static SBE_CONSTEXPR std::int64_t sourceOrderIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t sourceOrderIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t sourceOrderIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t sourceOrderIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t sourceOrderId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 56, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &sourceOrderId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 56, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *sourceOrderListIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceOrderListIdId() SBE_NOEXCEPT
    {
        return 16;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceOrderListIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceOrderListIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceOrderListIdEncodingOffset() SBE_NOEXCEPT
    {
        return 64;
    }

    static SBE_CONSTEXPR std::int64_t sourceOrderListIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t sourceOrderListIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t sourceOrderListIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t sourceOrderListIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t sourceOrderListId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 64, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &sourceOrderListId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 64, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *sourceTradeIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceTradeIdId() SBE_NOEXCEPT
    {
        return 17;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceTradeIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceTradeIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceTradeIdEncodingOffset() SBE_NOEXCEPT
    {
        return 72;
    }

    static SBE_CONSTEXPR std::int64_t sourceTradeIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t sourceTradeIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t sourceTradeIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t sourceTradeIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t sourceTradeId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 72, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &sourceTradeId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 72, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *sourceAllocationIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceAllocationIdId() SBE_NOEXCEPT
    {
        return 18;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceAllocationIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceAllocationIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceAllocationIdEncodingOffset() SBE_NOEXCEPT
    {
        return 80;
    }

    static SBE_CONSTEXPR std::int64_t sourceAllocationIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t sourceAllocationIdMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t sourceAllocationIdMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t sourceAllocationIdEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t sourceAllocationId() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 80, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &sourceAllocationId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 80, &val, sizeof(std::int64_t));
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
        return 19;
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
        return 88;
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
        std::memcpy(&val, m_buffer + m_offset + 88, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &price(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 88, &val, sizeof(std::int64_t));
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
        return 20;
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
        return 96;
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
        std::memcpy(&val, m_buffer + m_offset + 96, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &qty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 96, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *quoteQtyMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t quoteQtyId() SBE_NOEXCEPT
    {
        return 21;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t quoteQtySinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool quoteQtyInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t quoteQtyEncodingOffset() SBE_NOEXCEPT
    {
        return 104;
    }

    static SBE_CONSTEXPR std::int64_t quoteQtyNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t quoteQtyMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t quoteQtyMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t quoteQtyEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t quoteQty() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 104, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &quoteQty(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 104, &val, sizeof(std::int64_t));
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
        return 22;
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
        return 112;
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
        std::memcpy(&val, m_buffer + m_offset + 112, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AllocationReportEvent &commission(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 112, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *subscriptionIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t subscriptionIdId() SBE_NOEXCEPT
    {
        return 23;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t subscriptionIdSinceVersion() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD bool subscriptionIdInActingVersion() SBE_NOEXCEPT
    {
        return m_actingVersion >= subscriptionIdSinceVersion();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t subscriptionIdEncodingOffset() SBE_NOEXCEPT
    {
        return 120;
    }

    static SBE_CONSTEXPR std::uint16_t subscriptionIdNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT16;
    }

    static SBE_CONSTEXPR std::uint16_t subscriptionIdMinValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(0);
    }

    static SBE_CONSTEXPR std::uint16_t subscriptionIdMaxValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(65534);
    }

    static SBE_CONSTEXPR std::size_t subscriptionIdEncodingLength() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD std::uint16_t subscriptionId() const SBE_NOEXCEPT
    {
        if (m_actingVersion < 1)
        {
            return static_cast<std::uint16_t>(65535);
        }

        std::uint16_t val;
        std::memcpy(&val, m_buffer + m_offset + 120, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    AllocationReportEvent &subscriptionId(const std::uint16_t value) SBE_NOEXCEPT
    {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 120, &val, sizeof(std::uint16_t));
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

    AllocationReportEvent &putSymbol(const char *src, const std::uint8_t length)
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

    AllocationReportEvent &putSymbol(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    AllocationReportEvent &putSymbol(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

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
        return 201;
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

    AllocationReportEvent &putCommissionAsset(const char *src, const std::uint8_t length)
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

    AllocationReportEvent &putCommissionAsset(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putCommissionAsset(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    AllocationReportEvent &putCommissionAsset(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putCommissionAsset(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

    SBE_NODISCARD static const char *sourceSymbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *sourceSymbolCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t sourceSymbolSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool sourceSymbolInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    static SBE_CONSTEXPR std::uint16_t sourceSymbolId() SBE_NOEXCEPT
    {
        return 202;
    }

    static SBE_CONSTEXPR std::uint64_t sourceSymbolHeaderLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t sourceSymbolLength() const
    {
        std::uint8_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
        return (length);
    }

    std::uint64_t skipSourceSymbol()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *sourceSymbol()
    {
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
        const char *fieldPtr = m_buffer + sbePosition() + 1;
        sbePosition(sbePosition() + 1 + (lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getSourceSymbol(char *dst, const std::uint64_t length)
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

    AllocationReportEvent &putSourceSymbol(const char *src, const std::uint8_t length)
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

    std::string getSourceSymbolAsString()
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

    std::string getSourceSymbolAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSourceSymbolAsString();

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
    std::string_view getSourceSymbolAsStringView()
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

    AllocationReportEvent &putSourceSymbol(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSourceSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    AllocationReportEvent &putSourceSymbol(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSourceSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const AllocationReportEvent &_writer)
{
    AllocationReportEvent writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "AllocationReportEvent", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("eventTime": )";
    builder << +writer.eventTime();

    builder << ", ";
    builder << R"("transactTime": )";
    builder << +writer.transactTime();

    builder << ", ";
    builder << R"("priceExponent": )";
    builder << +writer.priceExponent();

    builder << ", ";
    builder << R"("qtyExponent": )";
    builder << +writer.qtyExponent();

    builder << ", ";
    builder << R"("commissionExponent": )";
    builder << +writer.commissionExponent();

    builder << ", ";
    builder << R"("allocationTransactionType": )";
    builder << '"' << writer.allocationTransactionType() << '"';

    builder << ", ";
    builder << R"("allocationReportType": )";
    builder << '"' << writer.allocationReportType() << '"';

    builder << ", ";
    builder << R"("allocationStatus": )";
    builder << '"' << writer.allocationStatus() << '"';

    builder << ", ";
    builder << R"("side": )";
    builder << '"' << writer.side() << '"';

    builder << ", ";
    builder << R"("counterPartyRole": )";
    builder << '"' << writer.counterPartyRole() << '"';

    builder << ", ";
    builder << R"("counterPartyExternalAccountId": )";
    builder << +writer.counterPartyExternalAccountId();

    builder << ", ";
    builder << R"("counterPartyOrderId": )";
    builder << +writer.counterPartyOrderId();

    builder << ", ";
    builder << R"("allocationReportId": )";
    builder << +writer.allocationReportId();

    builder << ", ";
    builder << R"("allocationId": )";
    builder << +writer.allocationId();

    builder << ", ";
    builder << R"("sourceOrderId": )";
    builder << +writer.sourceOrderId();

    builder << ", ";
    builder << R"("sourceOrderListId": )";
    builder << +writer.sourceOrderListId();

    builder << ", ";
    builder << R"("sourceTradeId": )";
    builder << +writer.sourceTradeId();

    builder << ", ";
    builder << R"("sourceAllocationId": )";
    builder << +writer.sourceAllocationId();

    builder << ", ";
    builder << R"("price": )";
    builder << +writer.price();

    builder << ", ";
    builder << R"("qty": )";
    builder << +writer.qty();

    builder << ", ";
    builder << R"("quoteQty": )";
    builder << +writer.quoteQty();

    builder << ", ";
    builder << R"("commission": )";
    builder << +writer.commission();

    builder << ", ";
    builder << R"("subscriptionId": )";
    builder << +writer.subscriptionId();

    builder << ", ";
    builder << R"("symbol": )";
    builder << '"' <<
        writer.getSymbolAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("commissionAsset": )";
    builder << '"' <<
        writer.getCommissionAssetAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("sourceSymbol": )";
    builder << '"' <<
        writer.getSourceSymbolAsJsonEscapedString().c_str() << '"';

    builder << '}';

    return builder;
}

void skip()
{
    skipSymbol();
    skipCommissionAsset();
    skipSourceSymbol();
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    std::size_t symbolLength = 0,
    std::size_t commissionAssetLength = 0,
    std::size_t sourceSymbolLength = 0)
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

    length += commissionAssetHeaderLength();
    if (commissionAssetLength > 254LL)
    {
        throw std::runtime_error("commissionAssetLength too long for length type [E109]");
    }
    length += commissionAssetLength;

    length += sourceSymbolHeaderLength();
    if (sourceSymbolLength > 254LL)
    {
        throw std::runtime_error("sourceSymbolLength too long for length type [E109]");
    }
    length += sourceSymbolLength;

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
