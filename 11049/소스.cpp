#include <cstdio>
#include <vector>
using namespace std;
unsigned dp[501][501];
unsigned list[501];

unsigned cal(int N)
{
	for (int dia = 1; dia <= N; dia++)
	{
		for (int i = 1; i <= N - dia + 1; i++)
		{
			int j = i + dia;
			dp[i][j] = (2 << 31) - 1;
			for (int k = i; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + list[i - 1] * list[k] * list[j]);
		}
	}
	return dp[1][N];
}
int main()
{
	int N, r, c;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &r, &c);
		list[i - 1] = r;
		list[i] = c;
	}
	printf("%d\n", cal(N));

}