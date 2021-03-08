#include <cstdio>
int arr[1001][1001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++)
		arr[i][0] = 1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++)
			arr[i][j] = (arr[i - 1][j] +  arr[i - 1][j - 1])%10007;
	}
	printf("%d\n", arr[N][K]);
}