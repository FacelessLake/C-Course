#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void longmul (char* n1, char* n2, int* ans) {
	int len1 = strlen(n1)-2;
	int len2 = strlen(n2)-2;
	int i, j;
	
	for(i = len1; i >= 0; i--)
		for (j = len2; j >= 0; j--) {
			int a = n1[i] - '0'; //from char to int
			int b = n2[j] - '0';
			ans[i+j] += a*b;
			
			int flag = 1;
			if (i+j == 0) flag = 0;
			
			//check for an overflow
			int count = i + j;
			while (flag == 1) {
				if (ans[count] > 9)
				{
					ans[count - 1] += ans[count] / 10;
					ans[count] = ans[count] % 10;
					count--;
				}
				else
					flag = 0;

				if (count == 0) flag = 0;
			}
		}
	for (i = 0; i <= len1 + len2; i++)
		printf("%d",ans[i]);
}


int main() {
	char* num1 = calloc(1010, sizeof(char));
	char* num2 = calloc(1010, sizeof(char));
	int* answ = calloc(2020, sizeof(int));

	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	fgets(num1, 1010, stdin);
	fgets(num2, 1010, stdin);
	
	longmul(num1, num2, answ);

	free(num1);
	free(num2);
	free(answ);
	return 0;
}