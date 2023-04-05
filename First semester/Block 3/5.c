#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[90001], b[90001], c[301], d[301];

int main() {
    int  n, m, i, iterx = 0, itery = 0, xcount = 0, ycount = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    
    for (i = 0; i < m; i++) {
        if (c[a[i]] != 0) {
            printf("%d", 0);
            return 0;
        }
        else xcount++;
        c[a[i]]++;
        
        if (d[b[i]] != 0) {
            itery++;
        }
        else ycount++;
        d[b[i]]++;
    }
    if (iterx == 0) printf("%d ", 1);
    if (xcount == n) printf("%d ", 2);
    if (itery == 0) printf("%d ", 3);
    if (ycount == n) printf("%d ", 4);
    if (itery == 0 && ycount == n) printf("%d ", 5);
    return 0;
}