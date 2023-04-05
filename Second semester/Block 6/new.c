#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int N, K;
	int from, to;
	int c;
	int tmp;
	int max_flow = 0;
	int flow[101][101];
	int cap[101][101];
	int visited[101];
	int que[101];
	int path[101];

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d", &N, &K);

	for (int i = 0; i < 101; i++)
	{
		memset(flow[i], 0, 101 * sizeof(int));
		memset(cap[i], 0, 101 * sizeof(int));
	}

	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d", &from, &to, &c);
		cap[from - 1][to - 1] = c;
		cap[to - 1][from - 1] = c;
	}


	while (1)
	{
		memset(visited, 0, sizeof(int) * 101);
		memset(que, 0, sizeof(int) * 101);
		memset(path, 0, sizeof(int) * 101);
		from = to = 0;
		que[to++] = 0;
		visited[0] = 1;
		while (from != to)
		{
			tmp = que[from];
			from++;
			for (int i = 0; i < N; i++)
			{
				if (cap[tmp][i] != 0 && visited[i] != 1 && cap[tmp][i] - flow[tmp][i] > 0)
				{
					visited[i] = 1;
					path[i] = tmp;
					que[to++] = i;
				}
			}
		}
		if (visited[N - 1] != 1)
			break;

		tmp = INT_MAX;

		for (int i = N - 1; i != 0; i = path[i])
		{
			c = path[i];
			tmp = min(tmp, cap[c][i] - flow[c][i]);
		}

		for (int i = N - 1; i != 0; i = path[i])
		{
			c = path[i];
			flow[c][i] += tmp;
			flow[i][c] -= tmp;
		}

		max_flow += tmp;
	}

	printf("%d", max_flow);

	return 0;
}