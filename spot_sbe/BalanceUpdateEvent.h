/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_BALANCEUPDATEEVENT_CXX_H_
#define _SPOT_SBE_BALANCEUPDATEEVENT_CXX_H_

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

class BalanceUpdateEvent
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
    static constexpr std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(27);
    static constexpr std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(601);
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

    BalanceUpdateEvent() = default;

    BalanceUpdateEvent(
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

    BalanceUpdateEvent(char *buffer, const std::uint64_t bufferLength) :
        BalanceUpdateEvent(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    BalanceUpdateEvent(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        BalanceUpdateEvent(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(27);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(601);
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

    BalanceUpdateEvent &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    BalanceUpdateEvent &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
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

    BalanceUpdateEvent &wrapForDecode(
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

    BalanceUpdateEvent &sbeRewind()
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
        BalanceUpdateEvent skipper(m_buffer, m_offset, m_bufferLength, m_actingBlockLength, m_actingVersion);
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

    BalanceUpdateEvent &eventTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *clearTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "optional";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t clearTimeId() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t clearTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool clearTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t clearTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 8;
    }

    static SBE_CONSTEXPR std::int64_t clearTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t clearTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t clearTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t clearTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t clearTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    BalanceUpdateEvent &clearTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::int64_t));
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
        return 3;
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
        return 16;
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
        std::memcpy(&val, m_buffer + m_offset + 16, sizeof(std::int8_t));
        return (val);
    }

    BalanceUpdateEvent &qtyExponent(const std::int8_t value) SBE_NOEXCEPT
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 16, &val, sizeof(std::int8_t));
        return *this;
    }

    SBE_NODISCARD static const char *freeQtyDeltaMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t freeQtyDeltaId() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t freeQtyDeltaSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool freeQtyDeltaInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t freeQtyDeltaEncodingOffset() SBE_NOEXCEPT
    {
        return 17;
    }

    static SBE_CONSTEXPR std::int64_t freeQtyDeltaNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t freeQtyDeltaMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t freeQtyDeltaMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t freeQtyDeltaEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t freeQtyDelta() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 17, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    BalanceUpdateEvent &freeQtyDelta(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 17, &val, sizeof(std::int64_t));
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
        return 5;
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
        return 25;
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
        std::memcpy(&val, m_buffer + m_offset + 25, sizeof(std::uint16_t));
        return SBE_LITTLE_ENDIAN_ENCODE_16(val);
    }

    BalanceUpdateEvent &subscriptionId(const std::uint16_t value) SBE_NOEXCEPT
    {
        std::uint16_t val = SBE_LITTLE_ENDIAN_ENCODE_16(value);
        std::memcpy(m_buffer + m_offset + 25, &val, sizeof(std::uint16_t));
        return *this;
    }

    SBE_NODISCARD static const char *assetMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *assetCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t assetSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool assetInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    static SBE_CONSTEXPR std::uint16_t assetId() SBE_NOEXCEPT
    {
        return 200;
    }

    static SBE_CONSTEXPR std::uint64_t assetHeaderLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t assetLength() const
    {
        std::uint8_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
        return (length);
    }

    std::uint64_t skipAsset()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *asset()
    {
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
        const char *fieldPtr = m_buffer + sbePosition() + 1;
        sbePosition(sbePosition() + 1 + (lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getAsset(char *dst, const std::uint64_t length)
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

    BalanceUpdateEvent &putAsset(const char *src, const std::uint8_t length)
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

    std::string getAssetAsString()
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

    std::string getAssetAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getAssetAsString();

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
    std::string_view getAssetAsStringView()
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

    BalanceUpdateEvent &putAsset(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putAsset(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    BalanceUpdateEvent &putAsset(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putAsset(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const BalanceUpdateEvent &_writer)
{
    BalanceUpdateEvent writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "BalanceUpdateEvent", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("eventTime": )";
    builder << +writer.eventTime();

    builder << ", ";
    builder << R"("clearTime": )";
    builder << +writer.clearTime();

    builder << ", ";
    builder << R"("qtyExponent": )";
    builder << +writer.qtyExponent();

    builder << ", ";
    builder << R"("freeQtyDelta": )";
    builder << +writer.freeQtyDelta();

    builder << ", ";
    builder << R"("subscriptionId": )";
    builder << +writer.subscriptionId();

    builder << ", ";
    builder << R"("asset": )";
    builder << '"' <<
        writer.getAssetAsJsonEscapedString().c_str() << '"';

    builder << '}';

    return builder;
}

void skip()
{
    skipAsset();
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(std::size_t assetLength = 0)
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += assetHeaderLength();
    if (assetLength > 254LL)
    {
        throw std::runtime_error("assetLength too long for length type [E109]");
    }
    length += assetLength;

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
