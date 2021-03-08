#include <cstdio>

typedef struct pos {
	int x;
	int y;
}Pos;

int main()
{
	Pos a[3];

	for (int i = 0; i < 3; i++)
		scanf("%d %d", &a[i].x, &a[i].y);

	int x, y;

	if (a[0].x == a[1].x)
		x = a[2].x;
	else if (a[0].x == a[2].x) {
		x = a[1].x;
	}
	else
		x = a[0].x;

	if (a[0].y == a[1].y)
		y = a[2].y;
	else if (a[0].y == a[2].y) {
		y = a[1].y;
	}
	else
		y = a[0].y;

	printf("%d %d", x, y);
}