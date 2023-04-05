#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[100001] = { 0 }, b[100001] = {0};
int main() {
    int  n1, n2, i = 0, min, count=0, num;
    scanf("%d", &n1);
    while (i < n1) {
        scanf("%d", &num);
        a[num]++;
        i++;
    }
    i = 0;
    scanf("%d", &n2);
    while (i < n2) {
        scanf("%d", &num);
        b[num]++;
        i++;
    }
    min = n1;
    if (n2 < min) min = n2; 
    for (i = 0; i < 100001; i++) {
        if (a[i] > 0 && b[i] == 0) count++;
    }
        printf("%d\n", count);
    if (count!=0)
    for (i = 0; i < 100001; i++) {
            if (a[i] > 0 && b[i] == 0) printf("%d ", i);;
    }
    return 0;
}