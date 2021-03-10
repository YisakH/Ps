#include <cstdio>
#include <algorithm>

int main()
{
	int a, b, c, tmp;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (!a && !b && !c)
			return 0;

		if (a > c) {
			tmp = c;
			c = a;
			a = tmp;
		}
		if (b > c) {
			tmp = b;
			b = c;
			c = tmp;
		}

		if (a * a + b * b == c * c)
			printf("right\n");
		else
			printf("wrong\n");
	}
}