#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int  l,r,k,i,j,d=0,answ=0,up,down;
    scanf("%d" "%d" "%d", &l, &r, &k);
    int dif;
    while ((r - k + 1) >= l)
    {
        dif = r - l;
        down = dif / (k-1); //определяем границы возможных шагов
        up = dif / k;
        answ += down - up;
        l++;
    }
    printf("%d", answ);
    return 0;
}
