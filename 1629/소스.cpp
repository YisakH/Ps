#include <cstdio>

int main()
{
	long long a, b, c;
	unsigned long long res = 1, cur;
	int i;
	scanf("%lld %lld %lld", &a, &b, &c);
	cur = a;
	for (i = 0; i < 64; i++) {
		if ((b >> i) & 1) {
			res = (res * cur) % c;
		}
		cur = (cur * cur) % c;
	}
	printf("%lld\n", res);
}