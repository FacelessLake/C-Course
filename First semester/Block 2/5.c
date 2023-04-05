#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    char  s = '.', last = '.';
    int  i=0;
    do {
        last = s;
        scanf("%c", &s);
        if (s == '.' && last != '.') i++;
    } while (s != '\n');
    if (last != '.') i++;
    printf("%d", i);
    return 0;
}