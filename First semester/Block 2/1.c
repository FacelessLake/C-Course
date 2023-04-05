#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
    int z, i;
    scanf("%d", &z);
    unsigned int a[5001];
    for (int i = 0; i < 5001; i++) {
        a[i] = i;
    }
    a[1] = 0;
    for (int s = 2; s < 5001; s++) {
        if (a[s] != 0) {
            for (int j = s * 2; j < 5001; j += s) {
                a[j] = 0;
            }
        }
    }
    for (i = 0; i <= z; i++) {
        if (a[i] != 0) {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}