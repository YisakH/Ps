#include <queue>
#include <cstdio>
#define MAX 2100000000
using namespace std;

int arr[1002][1002];

typedef struct point
{
	int x;
	int y;
	int dist;
};

int main()
{
	int N, M, i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i <= N+1; i++)
		for (j = 0; j <= M+1; j++)
			arr[i][j] = MAX;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			arr[i][j] = getchar();
			if (arr[i][j] < '0')
				arr[i][j] = getchar();
			arr[i][j] -= '0';
		}
	}

	queue<point> origin, jump;
	origin.push({ 1, 1, 1 });
	arr[1][1] = 1;

	while (!origin.empty()) { // 0 갈 수 있음, 1 = 벽임, -1 = 한번 뚫었던 벽임, 나머지 최단경로임
		int x = origin.front().x, y = origin.front().y, cnt = origin.front().dist;
		origin.pop();

		if (x == 0 || y == 0 || y > N || y > M) continue;

		if (arr[y][x - 1] == 0) {
			origin.push({ x - 1, y, cnt + 1 });
			arr[y][x - 1] = cnt + 1;
		}
		else if (arr[y][x - 1] ==1) {
			jump.push({ x - 1, y, cnt + 1 });
			arr[y][x - 1] = -1;
		}

		if (arr[y][x + 1] == 0) {
			origin.push({ x + 1, y, cnt + 1 });
			arr[y][x + 1] = cnt + 1;
		}
		else if (arr[y][x + 1] == 1) {
			jump.push({ x + 1, y, cnt + 1 });
			arr[y][x + 1] = -1;
		}

		if (arr[y-1][x] == 0) {
			origin.push({ x, y - 1, cnt + 1 });
			arr[y - 1][x] = cnt + 1;
		}
		else if (arr[y - 1][x] == 1) {
			jump.push({ x, y - 1, cnt + 1 });
			arr[y - 1][x] = -1;
		}

		if (arr[y + 1][x] == 0) {
			origin.push({ x, y + 1, cnt + 1 });
			arr[y + 1][x] = cnt + 1;
		}
		else if (arr[y + 1][x] == 1) {
			jump.push({ x, y + 1, cnt + 1 });
			arr[y + 1][x] = -1;
		}
	}

	while (!jump.empty()) {
		int x = jump.front().x, y = jump.front().y, cnt = jump.front().dist;
		jump.pop();
		if (x == 0 || y == 0 || y > N || x > M) continue;

		if (arr[y][x - 1] == 0) {
			jump.push({ x - 1, y, cnt + 1 });
			arr[y][x - 1] = cnt + 1;
		}
		if (arr[y][x + 1] == 0) {
			jump.push({ x + 1, y, cnt + 1 });
			arr[y][x + 1] = cnt + 1;
		}
		if (arr[y - 1][x] == 0) {
			jump.push({ x, y - 1, cnt + 1 });
			arr[y - 1][x] = cnt + 1;
		}
		if (arr[y + 1][x] == 0) {
			jump.push({ x, y + 1, cnt + 1 });
			arr[y + 1][x] = cnt + 1;
		}
	}
	if (arr[N][M] > 0)
		printf("%d\n", arr[N][M]);
	else
		printf("-1");
}