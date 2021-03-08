#include <cstdio>

int sum[1025][1025];

int main()
{
	int N, M, i, j, ipt;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++) {
			scanf("%d", &ipt);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + ipt - sum[i-1][j-1];
		}

	int x1, x2, y1, y2;
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		printf("%d\n", sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1-1][x1-1]);
	}
}