#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < math.h >
int main() {
    char  s;
    int  i,num=0,sw=0,j,N,iter=0;
    scanf("%d", &N);
    scanf("%c", &s);//считываем переход на новую строку заранее заранее
    for (j = 0; j<N; j+=8) {
        for (i = 0; i < 8; i++) {
            scanf("%c", &s);//считываем в виде знаков, потом превращаем в 1/0 и домножаем на двойку в степени i
            if (s == '0') sw = 0;
            if (s == '1') sw = 1;
            num += sw*pow(2, i);
            iter++;
            if (iter == N) break;
        }
        printf("%d ", num);
        num = 0;
    }
    return 0;
}