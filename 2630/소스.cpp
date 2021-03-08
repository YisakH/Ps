#include <cstdio>

bool arr[128][128];
int Wcnt, Bcnt;

void cal(int N, int y, int x)
{
	int i, j;
	bool color, failed = false;
	color = arr[y][x];
	for (i = y; i < N + y && !failed; i++) {
		for (j = x; j < N + x && !failed; j++) {
			if (color != arr[i][j])
				failed = true;
		}
	}

	if (!failed) {
		if (color == false)
			Wcnt++;
		else if (color == true)
			Bcnt++;
		return;
	}

	cal(N / 2, y, x);
	cal(N / 2, y + N / 2, x);
	cal(N / 2, y, x + N / 2);
	cal(N / 2, y + N / 2, x + N / 2);
}

int main()
{
	int N, i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	}
	cal(N, 0, 0);
	printf("%d\n", Wcnt);
	printf("%d\n", Bcnt);
	return 0;
}