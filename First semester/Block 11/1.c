#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define num 2000000

int arr[num];
int answ[1000000];

int HashTable(int* arry, int h, int k, int* count) {
	int iter = h;
	while (true) {
		if (arry[iter] == k) break;
		else
		{
			if (arry[iter] != 0) {
				if (iter != num) iter++;
				else iter = 0;
			}
			else {
				arry[iter] = k;
				*count += 1;
				break;
			}
		}
	}
	return(k);
}

//(not Leeroy)
uint32_t jenkins(const uint8_t* key, size_t len) {
	uint32_t hash = 0;
	for (int i = 0; i < len; i++) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

int main() {
	FILE* fp = fopen("input.bin", "rb");
	int szElem = 4;
	int N, i, key, j = 0, counter = 0;
	
	fread(&N, szElem, 1, fp);
	for (i = 0; i < N; i++) {
		fread(&key, szElem, 1, fp);
		if (key == 0) key = 1147147174; //for working zero
		int hash = jenkins(&key, szElem) % num;
		int check = counter;
		key = HashTable(arr, hash, key, &counter);
		if (check != counter) answ[counter]=key;
	}
	fclose(fp);

	int nul = 0;
	
	fp = fopen("output.bin", "wb");
	fwrite(&counter, szElem, 1, fp);
	for (i = 0; i <= counter; i++) {
		if (answ[i] == 1147147174) answ[i] = 0; //back to zero
	}
	fwrite(&answ[1], szElem, counter, fp);
	fclose(fp);
	return 0;
}