#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int arr[100001];

int main() {
    int i, N, Q, Y, l, r, c, al, ar;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &Q);
    for (i = 0; i < Q; i++) {
        scanf("%d", &Y);
        r = N - 1;
        l = 0;
        while (l < r - 1) {
            c = (l + r) / 2;
            if (Y <= arr[c]) r = c;
            else l = c;
        }
        al = abs(Y - arr[l]);
        ar = abs(Y - arr[r]);
        if (al < ar) printf("%d %d\n", l, al);
        else printf("%d %d\n", r, ar);
    }
    return 0;
}