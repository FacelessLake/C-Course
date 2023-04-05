#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[10001] = { 0 };
int main() {
    int  n, i, j, max, imax=0, jmax=0, count=0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        max = a[0];
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            count += a[j];
            if (count > max) {
                max = count;
                imax = i;
                jmax = j;
            }
        }
        count = 0;
    }
        printf("%d %d %d", imax, jmax, max);
    return 0;
}