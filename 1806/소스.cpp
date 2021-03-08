#include <cstdio>
int arr[100001], sum[100001];
int main()
{
	int N, S, st, end, minlen = 200000;
	scanf("%d %d", &N, &S);
	// sum[i] == (arr[1]부터 arr[i]까지 합)
	// arr[a]부터 arr[b]까지 합 == (sum[b] - sum[a-1])
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}

	st = end = 1;

	while (st <= N && end<=N)
	{
		if (sum[end] - sum[st - 1] < S)
			end++;
		else {
			if (end - st + 1 < minlen)
				minlen = end - st + 1;
			st++;
		}
	}
	if (minlen != 200000)
		printf("%d\n", minlen);
	else
		printf("0\n");
}