#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>


int my(int x1, int y1, int r1, int x2, int y2, int r2) {
	double dist, sub;
	int cross;

	dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	sub = abs(r2 - r1);

	if (r1 == r2 && x1 == x2 && y1 == y2)
		cross = -1;
	else if (dist - (r1 + r2) > 0.01) {
		cross = 0;
	}
	else if (abs(sub - dist) < 0.001 || abs(r1 + r2 - dist) < 0.001)
		cross = 1;
	else if (dist - abs(r1 - r2) < 0.001)
		cross = 0;
	else
		cross = 2;

	return cross;
}
int main()
{
	int x1, y1, r1, x2, y2, r2, T, t, cross;
	int dist, sub, add;
	scanf("%d", &T);


	for (t = 0; t < T; t++) {
		srand((unsigned)time(NULL));
		x1 = (rand()%20000)-10000;
		x2 = (rand() % 20000) - 10000;
		x1 = (rand() % 20000) - 10000;
		y1 = (rand() % 20000) - 10000;
		y2 = (rand() % 20000) - 10000;
		r1 = (rand() % 10000);
		r2 = (rand() % 10000);

		dist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		sub = (r1 - r2) * (r1 - r2);
		add = (r1 + r2) * (r1 + r2);

		if (r1 == r2 && x1 == x2 && y1 == y2)
			cross = -1;
		else if (dist > add) {
			cross = 0;
		}
		else if (sub == dist || add == dist)
			cross = 1;
		else if (dist < sub)
			cross = 0;
		else
			cross = 2;

		if (cross != my(x1, y1, r1, x2, y2, r2)) {
			printf("%d %d %d %d %d %d\n", x1, y1, r1, x2, y2, r2);
			return 0;
		}
	}
}
