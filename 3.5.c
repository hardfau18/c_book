#include "lib.h"
#include <assert.h>
#include <stdio.h>

/**
 * itob: converts integer into string of base b
 * n : integer to convert
 * s : destination string
 * b : base format 0,8,10,16 are allowed
 */
void itob(int n, char s[], int base) {
    int i = 0, sign = 1, chr;
    if (n < 0)
        sign = -1;
    do {
        chr = sign * (n % base) + '0';
        if (chr > '9')
            chr -= 9 + 'A';
        s[i++] = chr;
    } while ((n /= base) != 0);

    switch (base) {
    case 2:
        s[i++] = 'b';
        s[i++] = '0';
        break;
    case 8:
        s[i++] = '0';
        break;
    case 16:
        s[i++] = 'x';
        s[i++] = '0';
        break;
    }
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
}

int main() {
    char s_0[50];
    char s_8[20];
    char s_10[20];
    char s_16[20];
    int num = -2147483648;
    itob(num, s_0, 2);
    itob(num, s_8, 8);
    itob(num, s_10, 10);
    itob(num, s_16, 16);
    reverse(s_0);
    reverse(s_8);
    reverse(s_10);
    reverse(s_16);
    assert(!strcmp(s_0, "-0b10000000000000000000000000000000"));
    assert(!strcmp(s_8, "-020000000000"));
    assert(!strcmp(s_10, "-2147483648"));
    assert(!strcmp(s_16, "-0x80000000"));
    puts("Programm ran successfully");
    return 0;
}
