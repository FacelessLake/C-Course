#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
	int x = *(int*)a;
	int y = *(int*)b;
	return (x == y ? 0 : (x < y ? -1 : 1));
}

int main() {
	int N=0, M=0, i;
	
	scanf("%d", &N);
	  int* a = calloc(N, sizeof(int));
	  int* a2 = calloc(N, sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	scanf("%d", &M);
	  int* b = calloc(M, sizeof(int));
	  int* b2 = calloc(M, sizeof(int));
	for (i = 0; i < M; i++) {
		scanf("%d", &b[i]);
	}
	
	qsort(a, N, sizeof(a[0]), cmp);
	qsort(b, M, sizeof(b[0]), cmp);
	 
	  //delete repeated elements
	  int counter1 = 0;
	  a2[0] = a[0];
	  for (i = 1; i < N; i++) {
		  if (a2[counter1] != a[i]) {
			  counter1++;
			  a2[counter1] = a[i];
		  }
	  }

	  counter1++;
	  int counter2 = 0;
	  b2[0] = b[0];
	  for (i = 1; i < M; i++) {
		  if (b2[counter2] != b[i]) {
			  counter2++;
			  b2[counter2] = b[i];
		  }
	  }
	  counter2++;
	  
	  int* c = calloc(N + M, sizeof(int));
	  int Acounter = 0, Bcounter=0;
	  int iter = 0;
	//check; counter 1, counter2 as limits
	while(Acounter!=counter1) {
		if (a2[Acounter] < b2[Bcounter]) { c[iter++] = a2[Acounter++]; continue;}
		if (a2[Acounter] == b2[Bcounter]) { Acounter++; if (Bcounter<(counter2)) Bcounter++; continue;} //there is check for Bcounter being in it's limits
		if (a2[Acounter] > b2[Bcounter]) { if (Bcounter < (counter2)) Bcounter++; else c[iter++] = a2[Acounter++]; continue;} // here too
	}
	 
	 printf("%d\n", iter);
	 if (iter != 0)
	 for (i = 0; i < iter; i++) {
		 printf("%d ", c[i]);
	 }
	free(a);
	free(a2);
	free(b);
	free(b2);
	free(c);
	return 0;
}