#pragma comment (linker , "/STACK:50000000 ")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void DFS(char** arr, int ist, int jst) {
    arr[ist][jst] = '#';
    if (arr[ist + 1][jst] == ' ')
        DFS(arr, ist + 1, jst);
    if (arr[ist][jst+1] == ' ')
        DFS(arr, ist, jst+1);
    if (arr[ist][jst - 1] == ' ')
        DFS(arr, ist, jst - 1);
    if (ist != 0)
        if (arr[ist-1][jst] == ' ')
            DFS(arr, ist-1, jst);
    return 0;
}

int main() {
	int n, i, j;
    char** a;

	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	
    fscanf(in, "%d\n", &n);
    a = (char**)malloc(n * sizeof(char*));
    
    // take memory for strings
    for (i = 0; i < n; i++){
        a[i] = (char*)malloc(n * sizeof(char));
        for (j = 0; j < n; j++)
        {
            fscanf(in,"%c", &a[i][j]);
        }
        fscanf(in,"\n");
    }

    //find start
    int sti=0, stj=0;
    for (j = 0; j < n; j++)
        if (a[0][j] == ' ') {
            stj = j;
            break;
        }
    //first DFS
    DFS(a, sti, stj);

    //search for secret rooms and count them
    int count=0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == ' ') {
                count++;
                DFS(a, i, j);
            }
        }
    }

    //test
    /*
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            fprintf(out,"%c", a[i][j]);
        }
        fprintf(out,"\n");
    }
    */
    
    //answer
    fprintf(out, "%d\n", count);
    
    // Free the memory
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}