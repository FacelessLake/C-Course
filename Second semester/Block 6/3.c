#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define N 101

int que[N], flow[N][N], father[N], cap[N][N];

int minim(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int BFS(int start, int end) {
    int* mark = calloc(101, sizeof(int));
    mark[start] = 1;
    int fr = 0, to = 0;
    que[to++] = start;

    while (to > fr) {
        int v = que[fr++];
        for (int u = 1; u <= end; u++) {
            if (mark[u] == 0 && cap[v][u] - flow[v][u] > 0) { //cheñk the cf(uv) - residual capacity
                mark[u] = 1;
                que[to++] = u;
                father[u] = v;
            }
        }
    }
    if (mark[end] == 0){
        free(mark);
        return 0;
    }    
    else {
        free(mark);
        return 1;
    }
}

int FF(int source, int sink) {
    int max = 0;
    int i, fth;
    
    while (BFS(source, sink) == 1) {
        int minimum = INT_MAX;
        i = sink;
        while (i != source) { //restore the path P for the first time
            fth = father[i];
            minimum = minim(minimum, cap[fth][i] - flow[fth][i]);
            i = fth;
        }
        
        i = sink;
        while (i != source) { //restore the path P for the second
            fth = father[i];
            
            flow[fth][i] += minimum; 
            flow[i][fth] -= minimum; //Don't forget to change the flow on the back edge!
            
            i = fth;
        }
        max += minimum;
    }
    return max;
}

int main() {
    int n, k, i;
    int from, to, value;

    FILE* fr = fopen("input.txt", "r");
    FILE* fw = fopen("output.txt", "w");

    fscanf(fr, "%d %d\n", &n, &k);

    for (int i = 1; i <= k; i++)
    {
        fscanf(fr, "%d %d %d\n", &from, &to, &value);
        cap[from][to] = value;
        cap[to][from] = value;
    }

    fprintf(fw, "%d", FF(1, n));

    fclose(fr);
    fclose(fw);
    return 0;
}