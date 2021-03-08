#include <cstdio>
#include <cstring>
int arr[50][50];
int cnt = 0;
void search(int x, int y, int N, int M)
{
	if (x < 0 || y < 0 || y == N || x == M)
		return;
	arr[y][x] = cnt;
	if (arr[y][x - 1] == 10000)
		search(x - 1, y, N, M);
	if (arr[y][x + 1] == 10000)
		search(x + 1, y, N, M);
	if (arr[y-1][x] == 10000)
		search(x, y-1, N, M);
	if (arr[y + 1][x] == 10000)
		search(x, y+1, N, M);
}
int main()
{
	int N, M, K, n, m, x, y, i, T, t;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		scanf("%d %d %d", &M, &N, &K);
		cnt = 0;
		memset(arr, 0, sizeof(arr));

		for (i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			arr[y][x] = 10000;
		}

		for (n = 0; n < N; n++) {
			for (m = 0; m < M; m++) {
				if (arr[n][m] == 10000) {
					cnt++;
					search(m, n, N, M);
				}
			}
		}
		printf("%d\n", cnt);
	}
}