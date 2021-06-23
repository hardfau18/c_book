#include <assert.h>
#include <stdio.h>

/**
 * strindex: find right most occurance of string t in string s
 */
int strindex(char *s, char *t) {
    int i, j, k, ret;
    ret = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[j] == t[k] && s[j] != '\0' && t[k] != '\0';
             j++, k++)
            ;
        ret = t[k] == '\0' ? i : ret;
    }
    return ret;
}

int main() {
    char s[] = "Some random lines with random words need to ran";
    char t[] = "random";
    assert(strindex(s, t) == 23);
    puts("Programm ran successfully");
    return 0;
}
