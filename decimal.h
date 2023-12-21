#ifndef _SBE_APP_DECIMAL_H_
#define _SBE_APP_DECIMAL_H_

#include <unistd.h>
#include <cstdint>

struct Decimal {
    int64_t mantissa;
    int8_t exponent;
};

#endif
