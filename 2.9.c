#include <assert.h>
#include <stdio.h>

/**
 * bitcount : return number of 1 bit in num
 */
int bitcount(int num) {
    int cnt = 0;
    for (; num; cnt++)
        num &= num - 1;
    return cnt;
}

int main() {
    int num = 0b1010001011110011010001;
    assert(bitcount(num) == 11);
    return 0;
}
