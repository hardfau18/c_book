#include <assert.h>
#include <stdio.h>
#include <string.h>

/**
 * to_lower : converts the string s to its lower case
 */
void to_lower(char *s) {
    int i = 0;
    while (s[i] != '\0')
        s[i++] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] + 0x20 : s[i];

}

int main() {
    char s[] = "tshT EOOAU ? 2 98thS@# AThSTHAt hs";
    char res[] = "tsht eooau ? 2 98ths@# athsthat hs";
    to_lower(s);
    assert(!strcmp(s, res));
    return 0;
}
