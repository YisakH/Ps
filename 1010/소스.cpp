#include <cstdio>



int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int arr[31][31];
		int M, N;

		scanf("%d %d", &M, &N);
		for (int j = 0; j <= N; j++)
			for (int i = 0; i <= M; i++)
				if (i == 0 || i == j)
					arr[j][i] = 1;
				else
					arr[j][i] = 0;

		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= i && j <= M; j++) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}

		printf("%d\n", arr[N][M]);

		//nCr = n * n-1Cr-1

	}
}