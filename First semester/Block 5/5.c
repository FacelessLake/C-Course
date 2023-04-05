#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < string.h >
typedef struct LongNum_s {
    int len; //сколько цифр в числе
    int arr[501]; //массив десятичных цифр числа
} LongNum;
//struct LongNum l;
LongNum mass[2001];


LongNum sum(LongNum* mass1, LongNum* mass2) {
    LongNum answ = {0};
    //memset(answ.arr,'0',sizeof(answ.arr));
    answ.len = mass1->len;
    int i;
    for (i = 1; i <= mass1->len; i++) {
        answ.arr[i]+=mass1->arr[i];
        answ.arr[i]+=mass2->arr[i];
        if (answ.arr[i] > 9) {
            if(i==answ.len) answ.len++;
            answ.arr[i + 1] += answ.arr[i] / 10;
            answ.arr[i]= answ.arr[i] % 10;
        }
    }
    return answ;
}

int main() {
    int n,i;
    scanf("%d", &n);
    if (n == 1 || n == 2) {
        printf("1");
        return 0;
    }
    mass[1].len = 1;
    mass[1].arr[1] = 1;
    mass[2].len = 1;
    mass[2].arr[1] = 1;
    for (i = 3; i <= n; i++) {
        mass[i] = sum(&mass[i-1], &mass[i-2]);
    }

    for (i = mass[n].len;i>0;i--) {
        printf("%d",mass[n].arr[i]);
    }
    return 0;
}