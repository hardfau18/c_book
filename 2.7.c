#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "lib.h"

/**
 * setbits : returns x with the n bits that begin at position p set to the
 * rightmost n bits of y, leaving the other bits unchanged.
 * all indexing starts at 0
 * assumes p>n
 */
#define invert(x, p, n)  ((~mask(p,n)& x)|(~x & ~(~0<<n))<<(p+1-n))

int main() {
    uint16_t x = 0xc573, p = 11, n = 8, res = 0xc8c3;
    assert(invert(x,p,n)==res);
    return 0;
}
