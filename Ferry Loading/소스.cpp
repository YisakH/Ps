#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<int> chop;
int dp[5001][1001];

int solve(int N, int K)
{
	int a, b;
	if (dp[N][K] != -1)
		return dp[N][K];

	if (N < 3 * K)
		dp[N][K] = 2100000000;
	else if (K <= 0 || N <= 0)
		dp[N][K] = 0;
	else {
		a = solve(N - 1, K);
		b = solve(N - 2, K - 1) + pow(chop[N] - chop[N - 1], 2);
		dp[N][K] = (a < b) ? a : b;
	}
	return dp[N][K];
}

int main()
{
	int T, i, j, N, K, L;
	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &K, &N);
		K += 8;
		chop.clear();
		chop.assign(N+1, 0);
		// K : ¼Õ´Ô ¼ö, N : Á£°¡¶ôÀÇ °¹¼ö

		for (i = 1; i <= N; i++)
			scanf("%d", &chop[i]);
		for (i = 0; i <= 5000; i++)
			for (j = 0; j <= 1000; j++)
				dp[i][j] = -1;


		printf("%d\n", solve(N, K));
	}
	return 0;
}