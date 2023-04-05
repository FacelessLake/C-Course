#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char str[1000001]; 
char stra[101];
char* concat(char* pref, char* suff) {
    int i=0, j=0;
    while (pref[i]!= 0) {
        i++;
    }
    while (suff[j] != 0) {
        pref[i] = suff[j];
        j++;
        i++;
    }
}

int main() {
    int  n, i, len = 0;
    scanf("%d", &n);
    scanf("%s", str);
    for (i = 0; i < (n-1); i++) {
        scanf("%s", stra);
        concat(str, stra);
    }
    printf("%s", str);
    printf("\0");
    return 0;
}