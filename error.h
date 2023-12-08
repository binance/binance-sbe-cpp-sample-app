#ifndef _SBE_APP_ERROR_H_
#define _SBE_APP_ERROR_H_

#include <inttypes.h>
#include <optional>
#include <string>

#include "spot_sbe/ErrorResponse.h"

using spot_sbe::ErrorResponse;

struct Error {
    int16_t code;
    std::optional<int64_t> server_time;
    std::optional<int64_t> retry_after;
    std::string msg;

    explicit Error(ErrorResponse& decoder)
        : code{decoder.code()},
          server_time{decoder.serverTime()},
          retry_after{decoder.retryAfter()},
          msg{decoder.getMsgAsString()} {
        if (server_time == ErrorResponse::serverTimeNullValue()) {
            server_time.reset();
        }
        if (retry_after == ErrorResponse::retryAfterNullValue()) {
            retry_after.reset();
        }
        // Field "data" is only used for cancel replace responses so we omit it
        // in this example.
    }
};

#endif
