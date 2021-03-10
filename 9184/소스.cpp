#include <cstdio>
#define MINVAL -2100000000
int arr[21][21][21];

int cal(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		a = b = c = 20;

	if (arr[a][b][c] > MINVAL)
		return arr[a][b][c];

	if (a < b && b < c) {
		arr[a][b][c] = cal(a, b, c - 1) + cal(a, b - 1, c - 1) - cal(a, b - 1, c);
		return arr[a][b][c];
	}
	else {
		arr[a][b][c] = cal(a - 1, b, c) + cal(a - 1, b - 1, c) + cal(a - 1, b, c - 1) - cal(a - 1, b - 1, c - 1);
		return  arr[a][b][c];
	}
}

int main()
{
	int a, b, c, x, y, z;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			return 0;

		arr[0][0][0] = 1;

		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				for (int k = 0; k <= 20; k++)
					arr[i][j][k] = MINVAL;

		printf("w(%d, %d, %d) = %d\n",a, b, c, cal(a, b, c));
	}
}