#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char str[100];
char ho[3], mi[3], se[3];

int readTime(char* iStr, int* oHours, int* oMinutes, int* oSeconds){
    int i = 0, j=0;
    while (iStr[i] != '\0') {
        if (iStr[i] == '|') {
            *oHours = -1, * oMinutes = -1, * oSeconds = -1;
            return 0;
        }
        i++;
    }
    i = 0;
    
    while (iStr[i] != ':') {
        ho[j] = iStr[i];
        j++;
        i++;
    }
    ho[j] = '\0';
    j = 0;
    i++;
    
    while (iStr[i] != ':' && iStr[i] != '\0') {
        mi[j] = iStr[i];
        j++;
        i++;
    }
    mi[j] = '\0';
    j = 0;
    i++;
    
    while (iStr[i] != '\0') {
        se[j] = iStr[i];
        j++;
        i++;
    }
    se[j] = '\0';
    
    *oHours = atoi(ho);
    *oMinutes = atoi(mi);
    *oSeconds = atoi(se);
    if (*oHours > 23 || *oHours < 0 || *oMinutes > 59 || *oMinutes < 0 || *oSeconds > 59 || *oSeconds < 0) {
        *oHours = -1, *oMinutes = -1, *oSeconds = -1;
        return 0;
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int  h = 0, m = 0, s = 0, err;
    char* estr;
    sscanf("%s",&str);
    estr = &str;
    err=readTime(estr, &h, &m, &s);
    printf("%d %d %d %d\n", err, h, m, s);
    err = readTime(estr, &h, &m, &s);
    printf("%d %d %d\n", err, h, m);
    err = readTime(estr, &h, &m, &s);
    printf("%d %d\n", err, h);
    return 0;
}