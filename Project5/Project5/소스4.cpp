#include <stdio.h>
int arr[65];
long long cnt = 0;
int giul(int, int, int, int);

int check(int n)
{
	int i, j, check;
	check = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[i] == 0)
			continue;
		for (j = i + 1; j <= n; j++) {
			if (arr[j] == 0)
				continue;
			if (!giul(arr[i] / n + 1, arr[i] % n + 1, arr[j] / n + 1, arr[j] % n + 1))
				return 0;
		}
	}
	return 1;
}

int giul(int x1, int y1, int x2, int y2)
{
	int xv, yv;
	double a;
	xv = (x1 - x2), yv = (y1 - y2);
	if (xv == 0)
		return 1;
	a = yv / (double)xv;
	if (a == 1.0 || a == -1.0)
		return 0;
	return 1;
}
void make(int n, int k, int h, int last)
{
	int i, j, maxi, x1, y1, x2, y2;
	if (h == 0) {
		cnt++;
		return;
	}
	maxi = n * n - h + 1;
	for (i = last+1; i <= maxi; i++) {
		arr[n-h+1] = i;
		if (check(n))
			make(n, k, h - 1, i);
		arr[n - h+1] = 0;
	}
}

int main()
{
	int n, k, i, j;

	while (1)
	{
		cnt = 0;
		for (i = 1; i <= 8; i++)
			arr[i] = 0;
		scanf("%d %d", &n, &k);
		if (n == 0)
			break;
		make(n, k, k, 0);
		printf("%d\n", cnt);
	}
}