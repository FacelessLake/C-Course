#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char str[101];

void reverse(char* start, int len) {
    for (int i = len/2; i >= 0; i--) {
        int t = start[len - i];
        start[len - i] = start[i];
        start[i] = t;
    }
    printf("%s\n\0", start);
}

int main() {
    int  n, i, len = 0;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", str);
        len = strlen(str);
        reverse(str, len-1);
        len = 0;
    }
    return 0;
}