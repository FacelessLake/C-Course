#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[5001];

int main() {
    int i, N, j, M;
    scanf("%d %d", &N, &M);
    for (i = 0; i < 5001; i++) {
        arr[i] = i;
    }
    for (i = 0; i < N; i++) {
        arr[i] = i;
    }
    return 0;
}