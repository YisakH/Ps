#include <cstdio>

bool cal(int N, int cur)
{
	int sum = cur;

	while (cur > 0) {
		sum += cur % 10;
		cur /= 10;
	}

	if (N == sum)
		return true;
	else
		return false;
}

int main()
{
	int N, i;
	scanf("%d", &N);

	for (i = 1; i < N; i++) {
		if (cal(N, i)) {
			printf("%d\n", i);
			break;
		}
	}
	if (i == N)
		printf("0\n");
}