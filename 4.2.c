#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

/**
 * atof: converts float value present in string s into double,
 * can work on normal float or scientific values
 */
double atof(char *s) {
    double val = 0.0;
    int i, sign, psign, pwr = 0, dpoints = 0;
    // strip whitespaces
    for (i = 0; isspace(s[i]); i++)
        ;

    // get the sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        sign = 1;
        i++;
    } else
        sign = 1;
    // get the decimal digits
    for (; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
    }
    // if it contains . just increment it
    if (s[i] == '.')
        i++;
    for (; isdigit(s[i]); i++) {
        val = val * 10 + (s[i] - '0');
        dpoints++;
    }
    if (s[i] == 'e') {
        i++;
        // get the psign
        if (s[i] == '-') {
            psign = -1;
            i++;
        } else if (s[i] == '+') {
            psign = 1;
            i++;
        } else
            psign = 1;
        for (; isdigit(s[i]); i++) {
            pwr = pwr * 10 + (s[i] - '0');
        }
    }
    pwr *= psign;
    pwr -= dpoints;
    double ret = sign * val * (double)pow(10, pwr);
    return ret ;
}

int main() {
    char s1[] = "3.456e-4";
    char s2[] = " 7.56";
    char s3[] = "-0.396";
    // can't use assert for floats, can't check for equality without error
    printf("result: %e, value: %e \n", atof(s1), 3.456e-4);
    printf("result: %e, value: %e \n", atof(s2), 7.56);
    printf("result: %e, value: %e \n", atof(s3), -0.396);
    return 0;
}
