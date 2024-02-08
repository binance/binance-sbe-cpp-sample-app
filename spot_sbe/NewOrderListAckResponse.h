/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_NEWORDERLISTACKRESPONSE_CXX_H_
#define _SPOT_SBE_NEWORDERLISTACKRESPONSE_CXX_H_

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

class NewOrderListAckResponse
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
    static const std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(19);
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(309);
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

    NewOrderListAckResponse() = default;

    NewOrderListAckResponse(
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

    NewOrderListAckResponse(char *buffer, const std::uint64_t bufferLength) :
        NewOrderListAckResponse(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    NewOrderListAckResponse(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        NewOrderListAckResponse(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(19);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(309);
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

    NewOrderListAckResponse &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    NewOrderListAckResponse &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
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

    NewOrderListAckResponse &wrapForDecode(
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

    NewOrderListAckResponse &sbeRewind()
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
        NewOrderListAckResponse skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
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

    SBE_NODISCARD static const char *orderListIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t orderListIdId() SBE_NOEXCEPT
    {
        return 1;
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
        return 0;
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
        std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderListAckResponse &orderListId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *contingencyTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t contingencyTypeId() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t contingencyTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool contingencyTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t contingencyTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t contingencyTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t contingencyTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD ContingencyType::Value contingencyType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::uint8_t));
        return ContingencyType::get((val));
    }

    NewOrderListAckResponse &contingencyType(const ContingencyType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *listStatusTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t listStatusTypeId() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t listStatusTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool listStatusTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t listStatusTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 9;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t listStatusTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t listStatusTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 9, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD ListStatusType::Value listStatusType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 9, sizeof(std::uint8_t));
        return ListStatusType::get((val));
    }

    NewOrderListAckResponse &listStatusType(const ListStatusType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 9, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *listOrderStatusMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t listOrderStatusId() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t listOrderStatusSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool listOrderStatusInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t listOrderStatusEncodingOffset() SBE_NOEXCEPT
    {
        return 10;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t listOrderStatusEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t listOrderStatusRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD ListOrderStatus::Value listOrderStatus() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 10, sizeof(std::uint8_t));
        return ListOrderStatus::get((val));
    }

    NewOrderListAckResponse &listOrderStatus(const ListOrderStatus::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 10, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *transactionTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t transactionTimeId() SBE_NOEXCEPT
    {
        return 5;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t transactionTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool transactionTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t transactionTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 11;
    }

    static SBE_CONSTEXPR std::int64_t transactionTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t transactionTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t transactionTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t transactionTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t transactionTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 11, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    NewOrderListAckResponse &transactionTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 11, &val, sizeof(std::int64_t));
        return *this;
    }

    class Orders
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
        Orders() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize16Encoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint16_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 65534)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize16Encoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(8));
            dimensions.numInGroup(static_cast<std::uint16_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 8;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 8;
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

        inline Orders &next()
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
            GroupSize16Encoding dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint16_t>(m_count));
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
            return 1;
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
            return 0;
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
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Orders &orderId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int64_t));
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

        Orders &putSymbol(const char *src, const std::uint8_t length)
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

        Orders &putSymbol(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Orders &putSymbol(const std::string_view str)
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

        Orders &putClientOrderId(const char *src, const std::uint8_t length)
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

        Orders &putClientOrderId(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putClientOrderId(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Orders &putClientOrderId(const std::string_view str)
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
            std::basic_ostream<CharT, Traits> &builder, Orders &writer)
        {
            builder << '{';
            builder << R"("orderId": )";
            builder << +writer.orderId();

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
            skipSymbol();
            skipClientOrderId();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(
            std::size_t symbolLength = 0,
            std::size_t clientOrderIdLength = 0)
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

private:
    Orders m_orders;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t ordersId() SBE_NOEXCEPT
    {
        return 100;
    }

    SBE_NODISCARD inline Orders &orders()
    {
        m_orders.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_orders;
    }

    Orders &ordersCount(const std::uint16_t count)
    {
        m_orders.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_orders;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t ordersSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool ordersInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    class OrderReports
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
        OrderReports() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize16Encoding dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint16_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 65534)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize16Encoding dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(24));
            dimensions.numInGroup(static_cast<std::uint16_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 24;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 24;
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

        inline OrderReports &next()
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
            GroupSize16Encoding dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint16_t>(m_count));
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
            return 1;
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
            return 0;
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
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        OrderReports &orderId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int64_t));
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
            return 2;
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
            return 8;
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
            std::memcpy(&val, m_buffer + m_offset + 8, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        OrderReports &orderListId(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 8, &val, sizeof(std::int64_t));
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
            return 3;
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
            return 16;
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
            std::memcpy(&val, m_buffer + m_offset + 16, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        OrderReports &transactTime(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 16, &val, sizeof(std::int64_t));
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

        OrderReports &putSymbol(const char *src, const std::uint8_t length)
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

        OrderReports &putSymbol(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        OrderReports &putSymbol(const std::string_view str)
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

        OrderReports &putClientOrderId(const char *src, const std::uint8_t length)
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

        OrderReports &putClientOrderId(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putClientOrderId(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        OrderReports &putClientOrderId(const std::string_view str)
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
            std::basic_ostream<CharT, Traits> &builder, OrderReports &writer)
        {
            builder << '{';
            builder << R"("orderId": )";
            builder << +writer.orderId();

            builder << ", ";
            builder << R"("orderListId": )";
            builder << +writer.orderListId();

            builder << ", ";
            builder << R"("transactTime": )";
            builder << +writer.transactTime();

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
            skipSymbol();
            skipClientOrderId();
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return false;
        }

        SBE_NODISCARD static std::size_t computeLength(
            std::size_t symbolLength = 0,
            std::size_t clientOrderIdLength = 0)
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

private:
    OrderReports m_orderReports;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t orderReportsId() SBE_NOEXCEPT
    {
        return 101;
    }

    SBE_NODISCARD inline OrderReports &orderReports()
    {
        m_orderReports.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_orderReports;
    }

    OrderReports &orderReportsCount(const std::uint16_t count)
    {
        m_orderReports.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_orderReports;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t orderReportsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool orderReportsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static const char *listClientOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static const char *listClientOrderIdCharacterEncoding() SBE_NOEXCEPT
    {
        return "UTF-8";
    }

    static SBE_CONSTEXPR std::uint64_t listClientOrderIdSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    bool listClientOrderIdInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    static SBE_CONSTEXPR std::uint16_t listClientOrderIdId() SBE_NOEXCEPT
    {
        return 200;
    }

    static SBE_CONSTEXPR std::uint64_t listClientOrderIdHeaderLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t listClientOrderIdLength() const
    {
        std::uint8_t length;
        std::memcpy(&length, m_buffer + sbePosition(), sizeof(std::uint8_t));
        return (length);
    }

    std::uint64_t skipListClientOrderId()
    {
        std::uint64_t lengthOfLengthField = 1;
        std::uint64_t lengthPosition = sbePosition();
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + lengthPosition, sizeof(std::uint8_t));
        std::uint64_t dataLength = (lengthFieldValue);
        sbePosition(lengthPosition + lengthOfLengthField + dataLength);
        return dataLength;
    }

    SBE_NODISCARD const char *listClientOrderId()
    {
        std::uint8_t lengthFieldValue;
        std::memcpy(&lengthFieldValue, m_buffer + sbePosition(), sizeof(std::uint8_t));
        const char *fieldPtr = m_buffer + sbePosition() + 1;
        sbePosition(sbePosition() + 1 + (lengthFieldValue));
        return fieldPtr;
    }

    std::uint64_t getListClientOrderId(char *dst, const std::uint64_t length)
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

    NewOrderListAckResponse &putListClientOrderId(const char *src, const std::uint8_t length)
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

    std::string getListClientOrderIdAsString()
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

    std::string getListClientOrderIdAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getListClientOrderIdAsString();

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
    std::string_view getListClientOrderIdAsStringView()
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

    NewOrderListAckResponse &putListClientOrderId(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putListClientOrderId(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    NewOrderListAckResponse &putListClientOrderId(const std::string_view str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putListClientOrderId(str.data(), static_cast<std::uint8_t>(str.length()));
    }
    #endif

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
        return 201;
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

    NewOrderListAckResponse &putSymbol(const char *src, const std::uint8_t length)
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

    NewOrderListAckResponse &putSymbol(const std::string &str)
    {
        if (str.length() > 254)
        {
            throw std::runtime_error("std::string too long for length type [E109]");
        }
        return putSymbol(str.data(), static_cast<std::uint8_t>(str.length()));
    }

    #if __cplusplus >= 201703L
    NewOrderListAckResponse &putSymbol(const std::string_view str)
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
    std::basic_ostream<CharT, Traits> &builder, const NewOrderListAckResponse &_writer)
{
    NewOrderListAckResponse writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "NewOrderListAckResponse", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("orderListId": )";
    builder << +writer.orderListId();

    builder << ", ";
    builder << R"("contingencyType": )";
    builder << '"' << writer.contingencyType() << '"';

    builder << ", ";
    builder << R"("listStatusType": )";
    builder << '"' << writer.listStatusType() << '"';

    builder << ", ";
    builder << R"("listOrderStatus": )";
    builder << '"' << writer.listOrderStatus() << '"';

    builder << ", ";
    builder << R"("transactionTime": )";
    builder << +writer.transactionTime();

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("orders": [)";
        writer.orders().forEach(
            [&](Orders &orders)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << orders;
            });
        builder << ']';
    }

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("orderReports": [)";
        writer.orderReports().forEach(
            [&](OrderReports &orderReports)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << orderReports;
            });
        builder << ']';
    }

    builder << ", ";
    builder << R"("listClientOrderId": )";
    builder << '"' <<
        writer.getListClientOrderIdAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("symbol": )";
    builder << '"' <<
        writer.getSymbolAsJsonEscapedString().c_str() << '"';

    builder << '}';

    return builder;
}

void skip()
{
    auto &ordersGroup { orders() };
    while (ordersGroup.hasNext())
    {
        ordersGroup.next().skip();
    }
    auto &orderReportsGroup { orderReports() };
    while (orderReportsGroup.hasNext())
    {
        orderReportsGroup.next().skip();
    }
    skipListClientOrderId();
    skipSymbol();
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    const std::vector<std::tuple<
        std::size_t,
        std::size_t>> &ordersItemLengths = {},
    const std::vector<std::tuple<
        std::size_t,
        std::size_t>> &orderReportsItemLengths = {},
    std::size_t listClientOrderIdLength = 0,
    std::size_t symbolLength = 0)
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += Orders::sbeHeaderSize();
    if (ordersItemLengths.size() > 65534LL)
    {
        throw std::runtime_error("ordersItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: ordersItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(Orders::computeLength, e);
        #else
        length += Orders::computeLength(std::get<0>(e), std::get<1>(e));
        #endif
    }

    length += OrderReports::sbeHeaderSize();
    if (orderReportsItemLengths.size() > 65534LL)
    {
        throw std::runtime_error("orderReportsItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: orderReportsItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(OrderReports::computeLength, e);
        #else
        length += OrderReports::computeLength(std::get<0>(e), std::get<1>(e));
        #endif
    }

    length += listClientOrderIdHeaderLength();
    if (listClientOrderIdLength > 254LL)
    {
        throw std::runtime_error("listClientOrderIdLength too long for length type [E109]");
    }
    length += listClientOrderIdLength;

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
}
#endif
