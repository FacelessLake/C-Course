#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct SortType
{
	int key;
	char string[8];
}ST;
ST arr[10001];

int main() {
	int i, N, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %s", &arr[i].key, &arr[i].string);
	}
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (arr[j].key > arr[j + 1].key) {
                ST tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1]= tmp;
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d %s\n", arr[i].key, arr[i].string);
    }
}