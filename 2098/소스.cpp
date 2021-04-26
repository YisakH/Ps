#include <cstdio>
#include <algorithm>
#define MAXVAL 2100000000

using namespace std;

int W[16][16];
int dest[16][16];
int N;

int cal(int bit, int now)
{
	if (bit == (1<<N) - 1) {
		return 0;
	}
	bit |= (1 << now);

	for (int i = 0; i < N; i++) {
		if (!(bit & (1 << i)) && W[now][i] > 0) {
			if (dest[bit | (1 << i)][now] == MAXVAL)
				dest[bit | (1 << i)][now] = cal(bit | (1 << i), i) + W[now][i];
		}
	}
	
	int minval = MAXVAL;

	for (int i = 0; i < N; i++)
	{
		minval = min(minval, dest[bit | (1 << i)][now]);
	}
	return minval;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &W[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dest[i][j] = MAXVAL;

	printf("%d", cal(0, 0));
}