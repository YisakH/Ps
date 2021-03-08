#include <cstdio>

typedef struct man {
	int x;
	int y;
}Man;

int main()
{
	Man* manarr;
	int N;

	scanf("%d", &N);

	manarr = new Man[N];

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &manarr[i].x, &manarr[i].y);
	}
	
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (manarr[i].x < manarr[j].x && manarr[i].y < manarr[j].y)
				cnt++;
		}
		printf("%d ", cnt);
	}

}