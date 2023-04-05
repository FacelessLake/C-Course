#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 32


int Rec(FILE* out, int r, int n, int m, int* col, int* hasV, int* hasS, int* hasD, char** table, int maxdim) {

	if (r == m)
		return 1;

	for (int c = 0; c < n; c++) {
		if (table[r][c] == '.')
			continue;

		if (hasV[c] || hasS[r + c] || hasD[r - c + maxdim - 1])//clipping: if the vertical or diagonals are already beating
			continue; //then we will NOT place the queen

		col[r] = c;   //put the queen in a cell
		hasV[c] = hasS[r + c] = hasD[r - c + maxdim - 1] = 1;   //update the global state

		//start iterating over all options for r + 1 and subsequent lines
		int z = Rec(out, r + 1, n, m, col, hasV, hasS, hasD, table, maxdim);
		if (z)
			return 1;
		hasV[c] = hasS[r + c] = hasD[r - c + maxdim - 1] = 0; //roll back changes, returning exactly the state before the queen was set
		col[r] = c; //(we are sure that hasX [?] was all 0 before we wrote 1 there) 
	}
	return 0;
}

int main() {
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	int n = 0, m = 0, max = 0;

	fscanf(in, "%d %d\n", &m, &n);

	if (n > m)
		max = n;
	else
		max = m;

	int totald = 2 * max + 2;

	int sz = sizeof(int);
	int* hasV = (int*)calloc(n, sz);
	int* hasS = (int*)calloc(totald, sz);
	int* hasD = (int*)calloc(totald, sz);

	int* col = (int*)calloc(m, sz);

	char** table = (char**)malloc(sizeof(char*) * m);
	for (int i = 0; i < m; ++i) {
		table[i] = (char*)malloc(sizeof(char) * (n + 16));
	}

	for (int i = 0; i < m; i++)
		fgets(table[i], N, in);

	for (int i = 0; i < m; ++i)
		fprintf(stderr, "%s", table[i]);

	int z = Rec(out, 0, n, m, col, hasV, hasS, hasD, table, max);

	if (z == 1)
		fprintf(out, "NO");
	else {
		fprintf(out, "YES\n");
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (col[i] == j) {

					fprintf(out, "X");
				}
				else {
					fprintf(out, ".");
				}
			}
			fprintf(out, "\n");
		}
	}

	free(col);
	free(hasV);
	free(hasD);
	free(hasS);

	for (int i = 0; i < m; ++i) {
		free(table[i]);
	}
	free(table);

	return 0;
}