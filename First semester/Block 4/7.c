#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check[10000];

int main() {
    int  n, i, j, x=1;
    FILE* fp;
    fp=fopen("input.txt", "r");
    do
    {
        x = fgetc(fp);
        check[x]++;
    } while (x != EOF);
    for (i = 32; i <= 126; i++) {
        if (check[i] != 0) {
            printf("%c ", i);
            for (j = 0; j < check[i]; j++) {
                printf("%c", '#');
            }
            printf("\n");
        }
    }
    fclose(fp);
    return 0;
}