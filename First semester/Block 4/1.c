#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void printTime(int h, int m, int s){
    printf("%02d:%02d:%02d\n", h, m, s);
}

int main() {
    int  n, i, h=0, m=0, s=0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &h, &m, &s);
        printTime(h, m, s);
    }
    return 0;
}