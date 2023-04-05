#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//int count[40];
void dectobin(int* cnt, int val) {
	int i = 0;
	while (val>0)
	{
		cnt[i]= val % 2;
		val /= 2;
		i++;
	}
	cnt[i] = -1;
	return 0;
}

int fastpow(int* num, int* cntr, int m) {
	int i=0;
	int ans = 1;
	long long poww = *num;
	while (cntr[i] >= 0) {
		if (cntr[i] == 1) ans = (ans*poww) % m;
		i++;
		poww = (poww*poww) % m;//wut?
	}
	return ans;
}


int main() {
	int t, m, i;
	int answ;
	scanf("%d %d", &t, &m);
	int* a = calloc(t, sizeof(int));
	int* count = calloc(40, sizeof(int));
	for (i = 0; i < t; i++) {
		scanf("%d", &a[i]);
	}
	
	int eil = m - 2;
	dectobin(&count[0],eil);
	
	if (m == 2) {
		for (i = 0; i < t; i++) {
			if (a[i] % 2 == 0) answ = -1;
			else answ = 1;
			printf("%d\n", answ);
		}
	}
	else
	for (i = 0; i < t; i++) {
		answ = fastpow(&a[i],&count[0],m);
		if (answ < 1 || answ > m) answ = -1;
		printf("%d\n", answ);
	}
	free(a);
	free(count);
	return 0;
}