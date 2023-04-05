#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include < string.h >
typedef struct LongNum_s {
    int len;
    int arr[3001];
} LongNum;
//struct LongNum l;
LongNum mass[1001];


LongNum fac(LongNum* mass1, int cnt) {
    LongNum answ = { 0 };
    //memset(answ.arr,'0',sizeof(answ.arr));
    answ.len = mass1->len;
    int i,j;
    for (i = 1; i <= mass1->len; i++) {
        answ.arr[i] += mass1->arr[i];
        answ.arr[i] *= cnt;
    }
    for (i = 1; i <= mass1->len; i++) {
        j = i;
        while (answ.arr[j] > 9) {
            if (j >= answ.len) answ.len++;
            answ.arr[j + 1] += answ.arr[j] / 10;
            answ.arr[j] = answ.arr[j] % 10;
            j++;
        }
    }
    return answ;
}

int main() {
    int n, i;
    scanf("%d", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    mass[1].len = 1;
    mass[1].arr[1] = 1;
    mass[2].len = 1;
    mass[2].arr[1] = 2;
    for (i = 3; i <= n; i++) {
        mass[i] = fac(&mass[i - 1], i);
    }

    for (i = mass[n].len; i > 0; i--) {
        printf("%d", mass[n].arr[i]);
    }
    return 0;
}