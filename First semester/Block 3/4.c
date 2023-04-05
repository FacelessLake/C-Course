#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int  n, i, strt = 0, end = 0, max = 0, count = 0, mstr = 0, mend = 0;
    int a[5001] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) {
        if (a[i] < 0){
             if (count > max) {
                max = count;
                mstr = strt;
                mend = end;
             }
                count = 0;
                strt = i + 1;
                end = i + 1;
                continue;
        }
        count += a[i];
        end = i; 
    }
    if (count > max) {
        max = count;
        mstr = strt;
        mend = end;
    }
    printf("%d %d %d", mstr, mend, max);
    return 0;
}