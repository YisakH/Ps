#include <cstdio>

int cnt[10001];

int main()
{
	int N, inp;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &inp);
		cnt[inp]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < cnt[i]; j++) {
			printf("%d\n", i);
		}
	}


}