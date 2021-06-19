#include <assert.h>
#include <stdint.h>
#include <stdio.h>

/**
 * mask : creats a mask bits from start position to number of bits
 */
#define mask(start,bits) ((~(~0<<bits))<<(start-bits+1))

/**
 * setbits : returns x with the n bits that begin at position p set to the
 * rightmost n bits of y, leaving the other bits unchanged.
 * all indexing starts at 0
 * assumes p>n
 */
#define setbits(x, p, n, y)  ((~mask(p,n)& x)|(y & ~(~0<<n))<<(p+1-n))

int main() {
    uint16_t x = 0xc573, p = 11, n = 8, y=0xa2dc, res = 0xcdc3;
    assert(setbits(x,p,n,y)==res);
    return 0;
}
