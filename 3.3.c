#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * expand: expands shorthand notations like a-z,0-9 to abc..xyz, 012..89
 * s1: source string
 * s2: destination string
 */
void expand(char *s1, char *s2) {
    int i = 0, j = 0;
    for (; s1[i] != 0; i++) {
        if (s1[i] == '-') {
            char start = s1[i - 1], stop = s1[i + 1];
            if (start < stop &&
                ('0' <= start && stop <= '9' || 'a' <= start && stop <= 'z' ||
                 'A' <= start && stop <= 'Z')) {
                // start and stop characters will be printed in else condition
                start++;
                stop--;
                while (start <= stop)
                    s2[j++] = start++;
            } else
                s2[j++] = s1[i];
        } else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "aet -h-s A-d a-n X-M G-K-P 3-8 e-f-9 ";
    char *s2 = malloc(100);
    char res[] =
        "aet -hijklmnopqrs A-d abcdefghijklmn X-M GHIJKLMNOP 345678 ef-9 ";
    expand(s1, s2);
    assert(!strcmp(s2, res));
    puts("Program ran successfully");
    return 0;
}
