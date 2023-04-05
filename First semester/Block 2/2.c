#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
int main() {
    char a,b,c,i;
    scanf("%c%c%c", &a,&b,&c);
    switch (a)
    {
    case 'M':     i = 1; break;
    case 'T':     if (b == 'u') i=2; else i=4; break;
    case 'W':     i=3; break;
    case 'F':     i=5; break;
    case 'S':     if (b == 'a') i=6; else i=7; break;
    }
    printf("%d", i);
    return 0;
}