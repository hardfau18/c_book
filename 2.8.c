#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "lib.h"

/**
 * rightrot : returns number x right rotated by n bits
 */
#define rightrot(x, n)  ((unsigned)x>>n | (x & ~(~0 << n))<<(sizeof(x)*8 - n) )

int main() {
    uint16_t x = 0xa903, n = 8, res = 0x3a9;
    assert(rightrot(x,n)==res);
    return 0;
}
