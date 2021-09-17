#include <cstdio>
#include <algorithm>
using namespace std;

int arr[3][1000];
int dp[3][1001];

int main()
{
	int N, result = 2100000000;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &arr[0][i], &arr[1][i], &arr[2][i]);
	}
	
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[2][0] = dp[2][0];

	for (int start = 0; start < 3; start++) { // 시작 집 정하기
		for (int i = 0; i < 3; i++) {
			if (start == i) {
				dp[i][1] = 2100000000;
				continue;
			}
			dp[i][1] = arr[start][0] + arr[i][1];
		}
		for (int n = 2; n < N; n++) {
			dp[0][n] = min(dp[1][n - 1], dp[2][n - 1]) + arr[0][n];
			dp[1][n] = min(dp[0][n - 1], dp[2][n - 1]) + arr[1][n];
			dp[2][n] = min(dp[0][n - 1], dp[1][n - 1]) + arr[2][n];
		}

		for (int end = 0; end < 3; end++) {
			if (start == end) {
				dp[end][N - 1] = 210000000;
			}
		}
		result = min(result, min(dp[0][N - 1], min(dp[1][N - 1], dp[2][N - 1])));
	}
	printf("%d\n", result);
}
