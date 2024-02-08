#ifndef _SBE_APP_UTIL_H_
#define _SBE_APP_UTIL_H_

#include <span>

#include "spot_sbe/MessageHeader.h"

using spot_sbe::MessageHeader;

template <typename T>
T message_from_header(const std::span<char> buffer, const MessageHeader& header) {
    return T{buffer.data(), MessageHeader::encodedLength(), buffer.size(), header.blockLength(),
             header.version()};
}

#endif
