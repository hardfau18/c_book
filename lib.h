#include <string.h>

/**
 * mask : creats a mask bits from start position to number of bits
 */
#define mask(start,bits) ((~(~0<<bits))<<(start-bits+1))

/**
 * reverse: reverses the string s
 */
void reverse(char *s) {
    char tmp;
    int i = 0;
    int n = strlen(s) - 1;
    while (i < n) {
        tmp = s[i];
        s[i++] = s[n];
        s[n--] = tmp;
    }
}

