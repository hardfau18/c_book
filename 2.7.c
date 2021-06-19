#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "lib.h"

/**
 * invert : returns x with n bits toggled from position p
 */
#define invert(x, p, n)  ((~mask(p,n)& x)|(~x & ~(~0<<n))<<(p+1-n))

int main() {
    uint16_t x = 0xc573, p = 11, n = 8, res = 0xc8c3;
    assert(invert(x,p,n)==res);
    return 0;
}
