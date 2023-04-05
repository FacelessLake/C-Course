#pragma comment (linker , "/STACK:50000000 ")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000

typedef struct Edge {
    int fr, to;
} edge;

typedef struct Vector {
    edge* ary;
    int cap;
    int size;
}vector;

int d[N];
vector g[N];

typedef struct Step {
    int mark; //0 - white, 1 - grey, 2 - black
    int value;
}step;

void push(vector* v, edge e) {
    if (v->cap == 0) {
        v->cap++;
        v->ary = malloc(sizeof(edge));
    }
    if (v->cap != 0 && v->cap==v->size) {
        v->cap*=2;
        v->ary = realloc(v->ary, sizeof(edge)*v->cap);
    }
    v->ary[v->size] = e;
    v->size++;
}

void BFS (int ist, int jst, int start) {
    for (int i = 0; i < N; i++) {
        d[i] = INFINITY;
    }
    int que[N], fr = 0, to = 0;
    d[start] = 0;
    que[to++] = start;
    while (to > fr) {
        int v = que[fr++];
        for (int i = 0; i < g[v].size;i++) {
            int u = g[v].ary[i].to;
            if (d[u] == INFINITY) {
                d[u] = d[v] + 1;
                que[to++] = v;
            }
        }
    }
}

int main() {
    int n, m, i, j;
    char** a;
    step** b;

    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    fscanf(in, "%d %d\n", &n, &m);
    a = (char**)malloc(n * sizeof(char*));
    // take memory for strings
    for (i = 0; i < n; i++) {
        a[i] = (char*)malloc(m * sizeof(char));
        for (j = 0; j < m; j++)
        {
            fscanf(in, "%c", &a[i][j]);
        }
        fscanf(in, "\n");
    }

    b = (step**)malloc(n * sizeof(step*));
    // take memory for strings
    for (i = 0; i < n; i++) {
        b[i] = (char*)malloc(m * sizeof(step));
    }

    //find start and then do dfs
    step count;
    int answ, Si, Fi, Sj, Fj;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 'S') {
                Si = i;
                Sj = j;
                break;
            }
            /*if (a[i][j] == 'F') {
                Fi = i;
                Fj = j;
            }*/
            
        }
    }
    
    b[Si][Sj].mark = 1;
    b[Si][Sj].value = 0;
    BFS(a,b,Si,Sj,n,m,&count);

    //test
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
        {
            fprintf(out,"%c", a[i][j]);
        }
        fprintf(out,"\n");
    }

    //answer
    fprintf(out, "%d\n", answ);

    // Free the memory
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}