#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[2][100001];
int sum[2][100001];

int main()
{
	int n, i, j, T, t;

	scanf("%d", &T);

	for (t = 0; t < T; t++) {
		scanf("%d", &n);
		memset(sum, sizeof(sum), 0);
		for (i = 0; i < 2; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &arr[i][j]);
		sum[0][1] = arr[0][1];
		sum[1][1] = arr[1][1];

		for (i = 2; i <= n; i++)
		{
			sum[0][i] = max(arr[0][i] + sum[1][i - 1], arr[0][i] + sum[1][i - 2]);
			sum[1][i] = max(arr[1][i] + sum[0][i - 1], arr[1][i] + sum[0][i - 2]);
		}
		printf("%d\n", max(sum[0][n], sum[1][n]));
	}
}