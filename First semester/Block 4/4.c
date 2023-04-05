#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char str[103];

int calcLetters(char* iStr, int* oLowerCnt, int* oUpperCnt, int* oDigitsCnt){
    int i = 0, check = 0;
    while (iStr[i] != '\n') {
        check = iStr[i];
        if (check >= 48 && check <= 57) *oDigitsCnt+=1;
        if (check >= 65 && check <= 90) *oUpperCnt+=1;
        if (check >= 97 && check <= 122) *oLowerCnt+=1;
        i++;
    }
    return i;
}

int main() {
    int  sym=0, lo=0, up=0, dig=0, lett=0, line=0;
    FILE* fp;
    fp = fopen("input.txt", "r");
    char* estr;
    estr = fgets(str, 102, fp);
    do
    {
        sym=calcLetters(estr,&lo,&up,&dig);
        lett = lo + up;
        line++;
        printf("%s %d %s %d %s %d %s%d %s %d %s %d %s\n", "Line", line, "has", sym, "chars:", lett, "are letters (", lo, "lower,", up, "upper),", dig, "are digits.");
        estr = fgets(str, 102, fp);
        sym=0, lo = 0, up = 0, dig = 0, lett = 0;
    } while (estr != NULL);
    fclose(fp);
    return 0;
}