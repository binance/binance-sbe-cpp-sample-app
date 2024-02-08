#ifndef _SBE_APP_WEB_SOCKET_METADATA_H_
#define _SBE_APP_WEB_SOCKET_METADATA_H_

#include <cinttypes>
#include <span>
#include <string>
#include <vector>

#include "spot_sbe/RateLimitInterval.h"
#include "spot_sbe/RateLimitType.h"

using spot_sbe::RateLimitInterval;
using spot_sbe::RateLimitType;

struct WebSocketMetadata {
    struct RateLimit {
        RateLimitType::Value rate_limit_type;
        RateLimitInterval::Value interval;
        uint8_t interval_num;
        int64_t rate_limit;
        int64_t current;
    };

    uint16_t status;
    std::vector<RateLimit> rate_limits;
    std::string id;
    std::span<char> result;

    WebSocketMetadata(const uint16_t status,
                      std::vector<RateLimit>&& rate_limits,
                      std::string&& id,
                      const std::span<char> result)
        : status{status},
          rate_limits{std::move(rate_limits)},
          id{std::move(id)},
          result{result} {}
};

#endif
