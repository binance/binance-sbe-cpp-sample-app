#ifndef _SBE_APP_UTIL_H_
#define _SBE_APP_UTIL_H_

#include "spot_sbe/MessageHeader.h"

using spot_sbe::MessageHeader;

template <typename T>
T message_from_header(char* const buffer, const size_t buffer_size, const MessageHeader& header) {
    return T{buffer, MessageHeader::encodedLength(), buffer_size, header.blockLength(),
             header.version()};
}

#endif
