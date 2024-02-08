/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SPOT_SBE_ACCOUNTRESPONSE_CXX_H_
#define _SPOT_SBE_ACCOUNTRESPONSE_CXX_H_

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

class AccountResponse
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
    static const std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(64);
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(400);
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

    AccountResponse() = default;

    AccountResponse(
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

    AccountResponse(char *buffer, const std::uint64_t bufferLength) :
        AccountResponse(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    AccountResponse(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        AccountResponse(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(64);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(400);
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

    AccountResponse &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    AccountResponse &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
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

    AccountResponse &wrapForDecode(
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

    AccountResponse &sbeRewind()
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
        AccountResponse skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
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

    AccountResponse &commissionExponent(const std::int8_t value) SBE_NOEXCEPT
    {
        std::int8_t val = (value);
        std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int8_t));
        return *this;
    }

    SBE_NODISCARD static const char *commissionRateMakerMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t commissionRateMakerId() SBE_NOEXCEPT
    {
        return 2;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t commissionRateMakerSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool commissionRateMakerInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t commissionRateMakerEncodingOffset() SBE_NOEXCEPT
    {
        return 1;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateMakerNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateMakerMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t commissionRateMakerMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t commissionRateMakerEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t commissionRateMaker() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &commissionRateMaker(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *commissionRateTakerMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t commissionRateTakerId() SBE_NOEXCEPT
    {
        return 3;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t commissionRateTakerSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool commissionRateTakerInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t commissionRateTakerEncodingOffset() SBE_NOEXCEPT
    {
        return 9;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateTakerNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateTakerMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t commissionRateTakerMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t commissionRateTakerEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t commissionRateTaker() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 9, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &commissionRateTaker(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 9, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *commissionRateBuyerMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t commissionRateBuyerId() SBE_NOEXCEPT
    {
        return 4;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t commissionRateBuyerSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool commissionRateBuyerInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t commissionRateBuyerEncodingOffset() SBE_NOEXCEPT
    {
        return 17;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateBuyerNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateBuyerMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t commissionRateBuyerMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t commissionRateBuyerEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t commissionRateBuyer() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 17, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &commissionRateBuyer(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 17, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *commissionRateSellerMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t commissionRateSellerId() SBE_NOEXCEPT
    {
        return 5;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t commissionRateSellerSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool commissionRateSellerInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t commissionRateSellerEncodingOffset() SBE_NOEXCEPT
    {
        return 25;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateSellerNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t commissionRateSellerMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t commissionRateSellerMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t commissionRateSellerEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t commissionRateSeller() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 25, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &commissionRateSeller(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 25, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *canTradeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t canTradeId() SBE_NOEXCEPT
    {
        return 6;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t canTradeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool canTradeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t canTradeEncodingOffset() SBE_NOEXCEPT
    {
        return 33;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t canTradeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t canTradeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 33, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value canTrade() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 33, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    AccountResponse &canTrade(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 33, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *canWithdrawMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t canWithdrawId() SBE_NOEXCEPT
    {
        return 7;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t canWithdrawSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool canWithdrawInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t canWithdrawEncodingOffset() SBE_NOEXCEPT
    {
        return 34;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t canWithdrawEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t canWithdrawRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 34, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value canWithdraw() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 34, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    AccountResponse &canWithdraw(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 34, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *canDepositMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t canDepositId() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t canDepositSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool canDepositInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t canDepositEncodingOffset() SBE_NOEXCEPT
    {
        return 35;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t canDepositEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t canDepositRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 35, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value canDeposit() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 35, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    AccountResponse &canDeposit(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 35, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *brokeredMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t brokeredId() SBE_NOEXCEPT
    {
        return 9;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t brokeredSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool brokeredInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t brokeredEncodingOffset() SBE_NOEXCEPT
    {
        return 36;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t brokeredEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t brokeredRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 36, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value brokered() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 36, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    AccountResponse &brokered(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 36, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *requireSelfTradePreventionMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t requireSelfTradePreventionId() SBE_NOEXCEPT
    {
        return 10;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t requireSelfTradePreventionSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool requireSelfTradePreventionInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t requireSelfTradePreventionEncodingOffset() SBE_NOEXCEPT
    {
        return 37;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t requireSelfTradePreventionEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t requireSelfTradePreventionRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 37, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value requireSelfTradePrevention() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 37, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    AccountResponse &requireSelfTradePrevention(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 37, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *preventSorMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t preventSorId() SBE_NOEXCEPT
    {
        return 11;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t preventSorSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool preventSorInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t preventSorEncodingOffset() SBE_NOEXCEPT
    {
        return 38;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t preventSorEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t preventSorRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 38, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD BoolEnum::Value preventSor() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 38, sizeof(std::uint8_t));
        return BoolEnum::get((val));
    }

    AccountResponse &preventSor(const BoolEnum::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 38, &val, sizeof(std::uint8_t));
        return *this;
    }

    SBE_NODISCARD static const char *updateTimeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t updateTimeId() SBE_NOEXCEPT
    {
        return 12;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t updateTimeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool updateTimeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t updateTimeEncodingOffset() SBE_NOEXCEPT
    {
        return 39;
    }

    static SBE_CONSTEXPR std::int64_t updateTimeNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t updateTimeMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t updateTimeMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t updateTimeEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t updateTime() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 39, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &updateTime(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 39, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *accountTypeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t accountTypeId() SBE_NOEXCEPT
    {
        return 13;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t accountTypeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool accountTypeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t accountTypeEncodingOffset() SBE_NOEXCEPT
    {
        return 47;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t accountTypeEncodingLength() SBE_NOEXCEPT
    {
        return 1;
    }

    SBE_NODISCARD std::uint8_t accountTypeRaw() const SBE_NOEXCEPT
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 47, sizeof(std::uint8_t));
        return (val);
    }

    SBE_NODISCARD AccountType::Value accountType() const
    {
        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 47, sizeof(std::uint8_t));
        return AccountType::get((val));
    }

    AccountResponse &accountType(const AccountType::Value value) SBE_NOEXCEPT
    {
        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 47, &val, sizeof(std::uint8_t));
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
        return 14;
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
        return 48;
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
        std::memcpy(&val, m_buffer + m_offset + 48, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &tradeGroupId(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 48, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *uidMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t uidId() SBE_NOEXCEPT
    {
        return 15;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t uidSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool uidInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t uidEncodingOffset() SBE_NOEXCEPT
    {
        return 56;
    }

    static SBE_CONSTEXPR std::int64_t uidNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t uidMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t uidMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t uidEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t uid() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 56, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    AccountResponse &uid(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 56, &val, sizeof(std::int64_t));
        return *this;
    }

    class Balances
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
        Balances() = default;

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
            dimensions.blockLength(static_cast<std::uint16_t>(17));
            dimensions.numInGroup(static_cast<std::uint32_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 17;
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
            return 17;
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

        inline Balances &next()
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


        SBE_NODISCARD static const char *exponentMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t exponentId() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exponentSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool exponentInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t exponentEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        static SBE_CONSTEXPR std::int8_t exponentNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT8;
        }

        static SBE_CONSTEXPR std::int8_t exponentMinValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(-127);
        }

        static SBE_CONSTEXPR std::int8_t exponentMaxValue() SBE_NOEXCEPT
        {
            return static_cast<std::int8_t>(127);
        }

        static SBE_CONSTEXPR std::size_t exponentEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::int8_t exponent() const SBE_NOEXCEPT
        {
            std::int8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::int8_t));
            return (val);
        }

        Balances &exponent(const std::int8_t value) SBE_NOEXCEPT
        {
            std::int8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::int8_t));
            return *this;
        }

        SBE_NODISCARD static const char *freeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t freeId() SBE_NOEXCEPT
        {
            return 2;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t freeSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool freeInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t freeEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        static SBE_CONSTEXPR std::int64_t freeNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t freeMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t freeMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t freeEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t free() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Balances &free(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(std::int64_t));
            return *this;
        }

        SBE_NODISCARD static const char *lockedMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t lockedId() SBE_NOEXCEPT
        {
            return 3;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t lockedSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool lockedInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t lockedEncodingOffset() SBE_NOEXCEPT
        {
            return 9;
        }

        static SBE_CONSTEXPR std::int64_t lockedNullValue() SBE_NOEXCEPT
        {
            return SBE_NULLVALUE_INT64;
        }

        static SBE_CONSTEXPR std::int64_t lockedMinValue() SBE_NOEXCEPT
        {
            return INT64_C(-9223372036854775807);
        }

        static SBE_CONSTEXPR std::int64_t lockedMaxValue() SBE_NOEXCEPT
        {
            return INT64_C(9223372036854775807);
        }

        static SBE_CONSTEXPR std::size_t lockedEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD std::int64_t locked() const SBE_NOEXCEPT
        {
            std::int64_t val;
            std::memcpy(&val, m_buffer + m_offset + 9, sizeof(std::int64_t));
            return SBE_LITTLE_ENDIAN_ENCODE_64(val);
        }

        Balances &locked(const std::int64_t value) SBE_NOEXCEPT
        {
            std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
            std::memcpy(m_buffer + m_offset + 9, &val, sizeof(std::int64_t));
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

        Balances &putAsset(const char *src, const std::uint8_t length)
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

        Balances &putAsset(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        Balances &putAsset(const std::string_view str)
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
            std::basic_ostream<CharT, Traits> &builder, Balances &writer)
        {
            builder << '{';
            builder << R"("exponent": )";
            builder << +writer.exponent();

            builder << ", ";
            builder << R"("free": )";
            builder << +writer.free();

            builder << ", ";
            builder << R"("locked": )";
            builder << +writer.locked();

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

private:
    Balances m_balances;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t balancesId() SBE_NOEXCEPT
    {
        return 100;
    }

    SBE_NODISCARD inline Balances &balances()
    {
        m_balances.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_balances;
    }

    Balances &balancesCount(const std::uint32_t count)
    {
        m_balances.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_balances;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t balancesSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool balancesInActingVersion() const SBE_NOEXCEPT
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

    class ReduceOnlyAssets
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
        ReduceOnlyAssets() = default;

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

        inline ReduceOnlyAssets &next()
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

        ReduceOnlyAssets &putAsset(const char *src, const std::uint8_t length)
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

        ReduceOnlyAssets &putAsset(const std::string &str)
        {
            if (str.length() > 254)
            {
                throw std::runtime_error("std::string too long for length type [E109]");
            }
            return putAsset(str.data(), static_cast<std::uint8_t>(str.length()));
        }

        #if __cplusplus >= 201703L
        ReduceOnlyAssets &putAsset(const std::string_view str)
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
            std::basic_ostream<CharT, Traits> &builder, ReduceOnlyAssets &writer)
        {
            builder << '{';
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

private:
    ReduceOnlyAssets m_reduceOnlyAssets;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t reduceOnlyAssetsId() SBE_NOEXCEPT
    {
        return 102;
    }

    SBE_NODISCARD inline ReduceOnlyAssets &reduceOnlyAssets()
    {
        m_reduceOnlyAssets.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_reduceOnlyAssets;
    }

    ReduceOnlyAssets &reduceOnlyAssetsCount(const std::uint32_t count)
    {
        m_reduceOnlyAssets.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_reduceOnlyAssets;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t reduceOnlyAssetsSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool reduceOnlyAssetsInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const AccountResponse &_writer)
{
    AccountResponse writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "AccountResponse", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("commissionExponent": )";
    builder << +writer.commissionExponent();

    builder << ", ";
    builder << R"("commissionRateMaker": )";
    builder << +writer.commissionRateMaker();

    builder << ", ";
    builder << R"("commissionRateTaker": )";
    builder << +writer.commissionRateTaker();

    builder << ", ";
    builder << R"("commissionRateBuyer": )";
    builder << +writer.commissionRateBuyer();

    builder << ", ";
    builder << R"("commissionRateSeller": )";
    builder << +writer.commissionRateSeller();

    builder << ", ";
    builder << R"("canTrade": )";
    builder << '"' << writer.canTrade() << '"';

    builder << ", ";
    builder << R"("canWithdraw": )";
    builder << '"' << writer.canWithdraw() << '"';

    builder << ", ";
    builder << R"("canDeposit": )";
    builder << '"' << writer.canDeposit() << '"';

    builder << ", ";
    builder << R"("brokered": )";
    builder << '"' << writer.brokered() << '"';

    builder << ", ";
    builder << R"("requireSelfTradePrevention": )";
    builder << '"' << writer.requireSelfTradePrevention() << '"';

    builder << ", ";
    builder << R"("preventSor": )";
    builder << '"' << writer.preventSor() << '"';

    builder << ", ";
    builder << R"("updateTime": )";
    builder << +writer.updateTime();

    builder << ", ";
    builder << R"("accountType": )";
    builder << '"' << writer.accountType() << '"';

    builder << ", ";
    builder << R"("tradeGroupId": )";
    builder << +writer.tradeGroupId();

    builder << ", ";
    builder << R"("uid": )";
    builder << +writer.uid();

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("balances": [)";
        writer.balances().forEach(
            [&](Balances &balances)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << balances;
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
    {
        bool atLeastOne = false;
        builder << R"("reduceOnlyAssets": [)";
        writer.reduceOnlyAssets().forEach(
            [&](ReduceOnlyAssets &reduceOnlyAssets)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << reduceOnlyAssets;
            });
        builder << ']';
    }

    builder << '}';

    return builder;
}

void skip()
{
    auto &balancesGroup { balances() };
    while (balancesGroup.hasNext())
    {
        balancesGroup.next().skip();
    }
    auto &permissionsGroup { permissions() };
    while (permissionsGroup.hasNext())
    {
        permissionsGroup.next().skip();
    }
    auto &reduceOnlyAssetsGroup { reduceOnlyAssets() };
    while (reduceOnlyAssetsGroup.hasNext())
    {
        reduceOnlyAssetsGroup.next().skip();
    }
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(
    const std::vector<std::tuple<std::size_t>> &balancesItemLengths = {},
    const std::vector<std::tuple<std::size_t>> &permissionsItemLengths = {},
    const std::vector<std::tuple<std::size_t>> &reduceOnlyAssetsItemLengths = {})
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += Balances::sbeHeaderSize();
    if (balancesItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("balancesItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: balancesItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(Balances::computeLength, e);
        #else
        length += Balances::computeLength(std::get<0>(e));
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

    length += ReduceOnlyAssets::sbeHeaderSize();
    if (reduceOnlyAssetsItemLengths.size() > 2147483647LL)
    {
        throw std::runtime_error("reduceOnlyAssetsItemLengths.size() outside of allowed range [E110]");
    }

    for (const auto &e: reduceOnlyAssetsItemLengths)
    {
        #if __cplusplus >= 201703L
        length += std::apply(ReduceOnlyAssets::computeLength, e);
        #else
        length += ReduceOnlyAssets::computeLength(std::get<0>(e));
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
