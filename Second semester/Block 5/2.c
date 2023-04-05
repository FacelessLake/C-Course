#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 200010

typedef struct Edge {
    int fr, to;
} edge;

typedef struct Vector {
    edge* ary;
    int cap;
    int size;
}vector;

int d[N], que[N];
vector g[N];

void push(vector* v, edge e) {
    if (v->cap == 0) {
        v->cap++;
        v->ary = malloc(sizeof(edge));
    }
    if (v->cap != 0 && v->cap == v->size) {
        v->cap *= 2;
        v->ary = realloc(v->ary, sizeof(edge) * v->cap);
    }
    v->ary[v->size] = e;
    v->size++;
}

void BFS(int start) {
    for (int i = 0; i < N; i++) {
        d[i] = -1;
    }
    int fr = 0, to = 0;
    d[start] = 0;
    que[to++] = start;

    while (to > fr) {
        int v = que[fr++];
        for (int i = 0; i < g[v].size; i++) {
            int u = g[v].ary[i].to;
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                que[to++] = u;
            }
        }
    }
}

int main() {
    int n, m, i;

    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");

    fscanf(in, "%d %d\n", &n, &m);

    for (i = 0; i < m; i++) {
        edge ed;
        fscanf(in, "%d %d", &ed.fr, &ed.to);
        push(&g[ed.fr], ed);
    }
        BFS(1);

    for (i = 1; i <= n; i++) {
        fprintf(out, "%d\n", d[i]); //check
    }
    for (i = 0; i < N; i++) {
        free(g[i].ary);
    }
    return 0;
}