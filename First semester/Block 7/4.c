#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[100001];

int main() {
    int i, N, j, Q, X, R, Y, l, r, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &Q);
    scanf("%d", &X);
    l = -1;
    Y = X;
    r = N;
    while (l < r - 1) {
        c = (l + r) / 2;
        if (Y < arr[c]) r = c;
        else l = c;
    }
    if (l >= 0 && arr[l] == Y) R = l;
    else R = -1;
    printf("%d\n", R);
    for (j = 1; j < Q; j++) {
        scanf("%d", &X);
        Y = X + R;
        l = -1;
        r = N;
        while (l < r - 1) {
            c = (l + r) / 2;
            if (Y < arr[c]) r = c;
            else l = c;
        }
        if (l >= 0 && arr[l] == Y) R = l;
        else R = -1;
        printf("%d\n", R);
    }
    return 0;
}