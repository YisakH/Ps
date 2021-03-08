#include <cstdio>
#include <cmath>
static const long long STA = pow(10, 18);
typedef struct longint {
	long long high;
	long long low;
}LL;

LL add(LL a, LL b) {
	LL c;
	c.low = a.low + b.low;
	c.high = a.high + b.high;
	c.high += c.low / STA;
	c.low %= STA;
	return c;
}

LL arr[101][101];

int main()
{
	int n, m, i, j;

	scanf("%d %d", &n, &m);
	m = (n - m < m) ? n - m : m;
	for (i = 0; i < n; i++)
		arr[i][0] = { 0,1 };
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			arr[i][j] = add(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}
	if (arr[n][m].high != 0)
		printf("%lld", arr[n][m].high);
	printf("%lld", arr[n][m].low);
}