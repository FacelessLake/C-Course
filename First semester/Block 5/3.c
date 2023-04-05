#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct Label_s {
    char name[16]; //имя автора (заканчивается нулём)
    int age; //возраст автора (сколько лет)
} Label;
struct Label_s l;
Label arr[1001];

typedef struct NameStats_s {
    int cntTotal; //сколько всего подписей
    int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats;

typedef struct AgeStats_s {
    int cntTotal; //сколько всего подписей
    int cntAdults; //сколько подписей взрослых (хотя бы 18 лет)
    int cntKids; //сколько подписей детей (меньше 14 лет)
} AgeStats;

void calcStats(const Label* arr, int cnt, NameStats* oNames, AgeStats* oAges) {
    oNames->cntLong = 0;
    oNames->cntTotal = cnt;
    oAges->cntKids = 0;
    oAges->cntAdults = 0;
    oAges->cntTotal = cnt;
    for (int i = 0; i < cnt; i++) {
        if ((strlen(arr[i].name))>10) oNames->cntLong++;
        if (arr[i].age < 14) oAges->cntKids++;
        else if (arr[i].age >= 18) oAges->cntAdults++;
    }
}

int main() {
    int  n, i;
    NameStats name;
    AgeStats age;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d let\0", &l.name, &l.age);
        arr[i] = l;
    }
    calcStats(&arr, n, &name, &age);
    printf("names: total = %d\nnames: long = %d\n", name.cntTotal, name.cntLong);
    printf("ages: total = %d\nages: adult = %d\nages: kid = %d", age.cntTotal, age.cntAdults, age.cntKids);
    return 0;
}