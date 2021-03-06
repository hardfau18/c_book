#include "lib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

/**
 * itoa: converts integer into string
 * n : integer to convert
 * s : destination string
 */
void itoa(int n, char s[]) {
    int i = 0, sign = 1;
    if (n < 0)
        sign = -1;
    do {
        s[i++] = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
}

int main() {
    char s[20];
    int num = -2147483648;
    itoa(num, s);
    reverse(s);
    assert(!strcmp(s, "-2147483648"));
    puts("Programm ran successfully");
    return 0;
}
