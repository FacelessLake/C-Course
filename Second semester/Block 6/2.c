#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int Rec(int Sum, int Last, int n, int** a) {
	if (a[Sum][Last] == -1) { //-1 means, that calculation is not over
		int res = 0;
		if (Sum == n)
			res = 1; //one variant is done
		else {
			for (int x = 1; x <= min(Last, n - Sum); x++)  //checking all available x
			{
				res += Rec(Sum + x, x, n, a) % MOD;
				res %= MOD;
			}
		}
		a[Sum][Last] = res; //saving the result
	}
	return a[Sum][Last];
}


int main() {
	FILE* in = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	int n,i,j;
	
	fscanf(in, "%d", &n);
	
	//initialise a two-dimensional array
	int** a = (int**)malloc((n+1) * sizeof(int*));
	
	// take memory for "strings"
	for (i = 0; i <= n; i++) {
		a[i] = (int*)malloc((n+1) * sizeof(int));
		for (j = 0; j <= n; j++)
			a[i][j] = -1;
	}
	
	fprintf(out, "%d", Rec(0, n, n, a));
	
	return 0;
}