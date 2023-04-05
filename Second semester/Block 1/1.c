#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long mod(long long n, long long d)
{
	if (d == 0) return n;
	long long result = n % d;
	if (result < 0)
		result += d;
	return result;
}

int main(int argc, char** argv) {
	long long modul = 0, a, b, answ;
	int mode = 0;
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-m") == 0) modul = atoi(argv[i + 1]);
		if (strcmp(argv[i], "add") == 0) {
			a = atoi(argv[i + 1]);
			b = atoi(argv[i + 2]);
			mode = 1;
		}
		if (strcmp(argv[i], "sub") == 0) {
			a = atoi(argv[i + 1]);
			b = atoi(argv[i + 2]);
			mode = 2;
		}
		if (strcmp(argv[i], "mul") == 0) {
			a = atoi(argv[i + 1]);
			b = atoi(argv[i + 2]);
			mode = 3;
		}
	}
	if (mode == 0) {
		fprintf(stderr, "No parameters specified.");
		return 13;
	}
	if (mode == 1) {
		answ = mod((a + b), modul);
	}
	if (mode == 2) {
		answ = mod ((a - b), modul);
	}
	if (mode == 3) {
		answ = mod(a, modul);
		int check = mod(b, modul);
		answ = mod(answ*check, modul);
	}
	printf ("%lld", answ);
	return 0;
}