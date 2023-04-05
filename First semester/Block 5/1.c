#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;
struct DateTime_s d;
DateTime arr[50001];

DateTime min(const DateTime* arr, int cnt) {
    DateTime minim;
    int i;
    minim = arr[0];
    for (i = 1; i < cnt; i++) {
        if (arr[i].year<minim.year) {
            minim = arr[i];
        }
        else if (arr[i].year == minim.year) {
            if (arr[i].month < minim.month) {
                minim = arr[i];
            }
            else if (arr[i].month == minim.month) {
                if (arr[i].day < minim.day) {
                    minim = arr[i];
                }
                else if (arr[i].day == minim.day) {
                    if (arr[i].hours < minim.hours) {
                        minim = arr[i];
                    }
                    else if (arr[i].hours == minim.hours) {
                        if (arr[i].minutes < minim.minutes) {
                            minim = arr[i];
                        }
                        else if (arr[i].minutes == minim.minutes) {
                            if (arr[i].seconds <= minim.seconds) {
                                minim = arr[i];
                            }
                        }
                    }
                }
            }
        }
    }
    return minim;
}

int main() {
    DateTime minim;
    int  n,i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d", &d.year, &d.month, &d.day, &d.hours, &d.minutes, &d.seconds);
        arr[i] = d;
    }
    minim = min(&arr,n);
    printf("%d %d %d %d %d %d", minim.year, minim.month, minim.day, minim.hours, minim.minutes, minim.seconds);
    return 0;
}