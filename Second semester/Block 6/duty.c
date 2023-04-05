#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int Rec(char** a, int r, int N, int M, int* col, int* hasV, int* hasS, int* hasD) {
    if (r == M)
        return 0;

    for (int c = 0; c < N; c++) {
        if (a[r][c] == '.' || hasV[c] || hasS[r + c] || hasD[r - c])
            continue; //if queen "beats" the column and diagonals we wouldn't place our next queen here

        col[r] = c; //put the queen into the square
        hasV[c] = hasS[r + c] = hasD[r - c] = 1; //queen "beats" the column and diagonals

        if (Rec(a, r + 1, N, M, col, hasV, hasS, hasD) == 0) //recursion for the next strings
            return 0;
        
        hasV[c] = hasS[r + c] = hasD[r - c] = 0; //undo the last queen's standing
    }
    return 1;
}

main() {
    int N, M;
    
    FILE* fr = fopen("input.txt", "r");
    FILE* fw = fopen("output.txt", "w");
    fscanf(fr, "%d %d\n", &M, &N);
    
    int* coll = calloc(M, sizeof(int)); //position of the queen
    int* hasv = calloc(N, sizeof(int)); //which columns are been "beaten"
    int* hass = calloc(2*N, sizeof(int));
    int* hasd = calloc(2*N+1, sizeof(int)); //which diagonals are been "beaten"
    
    //we should take some memory for our chess table
    char** arr = (char**)calloc(M, sizeof(char*));
    for (int i = 0; i < M; i++) {
        arr[i] = (char*)calloc(N, sizeof(char));
        for (int j = 0; j < N; j++) {
            fscanf(fr, "%c", &arr[i][j]);
        }
        fscanf(fr, "\n");
    }
    
    int r = 0;
    int answ = Rec(arr, r, N, M, coll, hasv, hass, &hasd[N]);
    
    if (answ == 0) {
        fprintf(fw,"YES\n");
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == '?')
                    if (j == coll[i])
                        arr[i][j] = 'X';
                    else
                        arr[i][j] = '.';
                fprintf(fw, "%c", arr[i][j]);
            }
            fprintf(fw, "\n");
        }
    }
    else
        fprintf(fw,"NO\n");

    for (int i = 0; i < M; ++i) {
        free(arr[i]);
    }
    
    free(arr);
    free(coll);
    free(hasv);
    free(hass);
    free(hasd);
	return 0;
}