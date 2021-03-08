#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001];
int main()
{
	int N, K, w, v;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &w, &v);
		for (int j = K; j >= w; j--) {
			dp[j] = max(dp[j - w] + v, dp[j]);
		}
	}
	printf("%d\n", dp[K]);
}