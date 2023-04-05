#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int  a, i, count;
    double z = 0, p = 0, n = 0, cz, cp, cn;
    scanf("%d", &count);
    for (i = 0; i < count; i++) {
        scanf("%d", &a);
        if (a > 0) p++;
        if (a == 0) z++;
        if (a < 0) n++;
    }
    cz = z / count;
    cn = n / count;
    cp = p / count;
    printf("%0.5lf " "%0.5lf " "%0.5lf ", cn, cz, cp);
    return 0;
}