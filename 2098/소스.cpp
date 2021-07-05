#include <cstdio>
#include <cmath>

using namespace std;

int W[17][17];
int dist[66000][17];
int N;

int solve(int, int);

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &W[i][j]);

	printf("%d\n", solve(1, 0));

	int tmp = pow(2, N);
	return 0;
}

int solve(int visit, int pos)
{
	if (dist[visit][pos] > 0)
		return dist[visit][pos];
	
	else if (visit == pow(2, N) - 1)
	{
		if (W[pos][0] > 0)
			return W[pos][0];
		else
			return -1;
	}

	

	int min = 2100000000;

	for (int i = 0; i < N; i++) {
		if (W[pos][i] > 0 && !(visit & (1 << i))) {
			int cal = solve(visit | (1 << i), i);
			if (cal >= 0) {
				cal += W[pos][i];

				min = (min < cal) ? min : cal;
			}
		}
	}
	dist[visit][pos] = min;
	return min;
}