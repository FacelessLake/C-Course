#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < string.h >
char str[1000001]; 
char stra[101];

char* concat(char* pref, char* suff) {
    int i=0;
    while (suff[i] != 0) {
        pref[i] = suff[i];
        i++;
    }
    return &pref[i];
}

int main() {
    int  n, i;
    char* start;
    scanf("%d", &n);
    scanf("%s", str);
    int len = strlen(str);
    start = &str[len];
    for (i = 0; i < (n-1); i++) {
        scanf("%s", stra);
        start=concat(start, stra);
    }
    printf("%s", str);
    printf("\0");
    return 0;
}