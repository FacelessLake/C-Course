#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
unsigned long a[20000001];
int num[200001];
int main() {
    int q, n, i;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < 20000001; i++) {
        a[i] = i;
    }
    a[1] = 0;
    for (int s = 2; s < n; s++) {
        if (a[s] != 0) {
            for (int j = s * 2; j < n; j += s) {
                a[j] = 0;
            }
        }
    }
    for (i = 0; i < q; i++) {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < q; i++) {
        printf("%d ",num[i]);
        if (a[num[i]]==0) printf("not\n");
        else printf("prime\n");
    }
    return 0;
}