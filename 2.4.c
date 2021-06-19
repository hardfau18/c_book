#include <stdio.h>
#include <string.h>
#include <assert.h>

void squeeze(char* s1, char* s2){
    int i,j,k;
    for(i=j=0; s1[i] != '\0'; i++){
        s1[j] = s1[i];
        for(k=0; s2[k] != '\0'; k++){
            if (s1[j] == s2[k])
                j--;
        }
        j++;
    }
    s1[j]='\0';
}

int main() {
    char s1[]= "This is some string";
    char s2[]= "is";
    char result[] = "Th  ome trng";
    squeeze(s1, s2);
    assert(!strcmp(s1, result));
    return 0;
}
