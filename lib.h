/**
 * mask : creats a mask bits from start position to number of bits
 */
#define mask(start,bits) ((~(~0<<bits))<<(start-bits+1))
