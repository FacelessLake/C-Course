#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int  n,i,j;
    scanf("%d", &n);
    int a[100], b[100] = {0};
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (a[i] > a[j]) b[i]++;
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}