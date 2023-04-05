#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include < string.h >
#define SIZE 1000100 //delete

typedef struct Node {
	char* value;
	struct Node* next; //0 if there aren't any value
} Node;

Node* arr[SIZE]; //delete

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Node* arr = calloc(); //initialize two-dimen arr (from another task)

	int n,i, index;
	char val[7];
	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %s\n", &index, &val);
		
		if (arr[index]->value == NULL)
			strcpy(arr[index]->value, *val); //first time
		else {
			Node* nn = malloc(sizeof(Node)); //not first time
			nn->value = "666666";
			nn->next = first;
			first = nn;
		}
	}

	/*for (Node* p = first; p; p = p->next)
		printf("%s\n", p->value);
	
	*/
	return 0;
}