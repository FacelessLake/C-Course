#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int  n, i=1, step=1, count=0;
    scanf("%d", &n);
    int a[100001];
    while (i<=n) {
        scanf("%d", &a[i]);
        i++;
    }
    while (step <= n) {
        for (i = step; i <=n; i += step) {
            count += a[i];
        }
        step++;
        printf("%d\n", count);
        count = 0;
    }
    return 0;
}