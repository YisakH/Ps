#include <cstdio>

bool net[101][101], visited[101];
int cnt;

void cal(int curpos, int N)
{
	int i;
	if (visited[curpos])
		return;
	else {
		cnt++;
		visited[curpos] = true;
	}
	for (i = 1; i <= N; i++) {
		if (net[curpos][i])
			cal(i, N);
	}
}

int main()
{
	int N, K, i, j, inp1, inp2;
	scanf("%d %d", &N, &K);

	for (i = 0; i < K; i++) {
		scanf("%d %d", &inp1, &inp2);
		net[inp1][inp2] = true;
		net[inp2][inp1] = true;
	}
	cal(1, N);
	printf("%d\n", cnt-1);
}