#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef unsigned int bitword;

void bitsetZero(bitword* arr, int num) {
    for (int i = 0; i < num; i++) {
        arr[i] = 0;
    }
}
int bitsetGet(const bitword* arr, int idx) {
    return (arr[idx / 8] & (128 >> (idx % 8)));
}
void bitsetSet(bitword* arr, int idx, int newval) {
    if (newval == 0) arr[idx / 8] = arr[idx / 8] & ~(128 >> (idx % 8));
    if (newval == 1) arr[idx / 8] = arr[idx / 8] | (128 >> (idx % 8));
}
int bitsetAny(const bitword* arr, int left, int right) {
    while (left < right) {
        if (left % 8 == 0 && ((left + 7) < right))
            if (arr[left / 8] != 0)  return 1;
            else { left += 8; continue;}
        if ((arr[left / 8] & (128 >> (left % 8)))!=0) return 1;
        left++;
    } 
    return 0;
}

bitword arr[12510];

int main() {
    int i, N, t, a, b;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &t);
        if (t == 0) {
            scanf("%d", &a);
            bitsetZero(&arr, a);
        }
        if (t == 1) {
            scanf("%d", &b);
            printf("%d\n", bitsetGet(&arr, b));
        }
        if (t == 2) {
            scanf("%d %d", &a, &b);
            bitsetSet(&arr, a, b);
        }
        if (t == 3) {
            scanf("%d %d", &a, &b);
            int l = bitsetAny(&arr, a, b);
            if (l == 0) printf("none\n");
            else printf("some\n");
        }
    }
   return 0;
}