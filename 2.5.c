#include <stdio.h>
#include <assert.h>

/**
 * strbrk : returns index of first occurance character from s in accept. if not
 * found it will return -1 s : string to be searched accept : string of
 * characters to search
 */
int strbrk(char *s, char *accept) {
    int ret = -1, i = 0;
    for (int j = 0; accept[j] != '\0'; j++) {
        for (i = 0; s[i] != accept[j] && s[i] != '\0'; i++);
        if (s[i] != '\0')
            ret = (unsigned int)ret < i ? ret:i ;
    }
    return ret;
}
int main() {
    char s[] = "abcdefgh";
    char accept[] = "fdnt";
    printf("value %d\n", strbrk(s,accept));
    assert(strbrk(s, accept)== 3);
}
