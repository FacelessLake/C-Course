#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Node{
    double value;
    int next;
}Node;
struct Node l;
Node arr[100000];

int main() {
    int  n, i, iter;
    scanf("%d %d", &n, &iter);
    for (i = 0; i < n; i++) {
        scanf("%lf %d", &l.value, &l.next);
        arr[i].value = l.value;
        arr[i].next = l.next;
    }
    while (iter != -1) {
        printf("%0.3lf\n", arr[iter].value);
        iter = arr[iter].next;
    }
    return 0;
}