#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long int arr[30001];

int main() {
    int i, j, n, counter=0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%llx", &arr[i]);
    }
    
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if ((arr[i] & arr[j]) == 0) counter++;
        }
    }
    printf("%d", counter);
    return 0;
}