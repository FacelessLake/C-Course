#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(/*int argc, char** argv*/) {
	
	FILE* fp = fopen("input.txt", "r");
	FILE* f = fopen("output.txt", "w");
	int sz = sizeof(char);
	
	char* string = calloc (110, sz);
	char* newstring = calloc(110, sz);

	fgets (string, 110, fp);
	int i = 0, covcounter = 0;

	while (string[i]!='\0' && string[i] != '\n') {
		int  j = 0;
		if (string[i] == ' ') i++;
		if (string[i] == '"') {
			i++;
			while (string[i] != '"') {
				newstring[j] = string[i];
				i++;
				j++;
			}
			i++;
			newstring[j] = '\0';
			fprintf(f, "[%s]\n", newstring);
		}
		else {
			while (string[i] != ' ' && string[i] != '\0' && string[i] != '\n') {
				newstring[j] = string[i];
				j++;
				i++;
			}
			newstring[j] = '\0';
			fprintf(f, "[%s]\n", newstring);
		}
	}
	
	free(string);
	free(newstring);
	return 0;
}