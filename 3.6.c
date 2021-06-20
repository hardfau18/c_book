#include "lib.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

/**
 * itoa_p: converts integer into string with padding
 * n : integer to convert
 * s : destination string
 * min : if resultant string is smaller than min then it is padded with spaces
 */
void itoa_p(int n, char s[], int min) {
    int i = 0, sign = 1;
    if (n < 0)
        sign = -1;
    do {
        s[i++] = sign * (n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    for (; i < min; i++) {
        s[i] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[20];
    int num = -2147483648;
    itoa_p(num, s, 20);
    assert(!strcmp(s, "         -2147483648"));
    puts("Programm ran successfully");
    return 0;
}
