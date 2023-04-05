#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int  n, i, num=0;
    int a[10001] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        a[num]++;
    }
    for (i = 0; i < 10001; i++) {
        if(a[i]!=0) printf("%d: %d\n", i, a[i]);
    }
    return 0;
}