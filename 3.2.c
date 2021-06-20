#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * escape: escapes the '\t', '\n' characters so that they are printed visualy
 * t: destination string
 * s: source string
 */
void escape(char *s, char *t) {
    int i = 0;
    for (; s[i] != 0; i++) {
        switch (s[i]) {
        case '\t':
            t[i] = '\\';
            t[++i] = 't';
            break;
        case '\n':
            t[i] = '\\';
            t[++i] = 'n';
            break;
        default:
            t[i] = s[i];
        }
    }
    t[i] = s[i];
}

int main() {
    char s[] = "abc\tted\t \ntsnhu";
    char *t = malloc(2 * strlen(s));
    char res[] = "abc\\ted\\t\\nsnhu";
    escape(s, t);
    assert(!strcmp(t, res));
    return 0;
}
