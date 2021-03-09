#include <cstdio>

bool check(int num)
{
	int cnt = 0;
	while (num > 0) {
		if (num % 10 == 6)
			cnt++;
		else
			cnt = 0;


		if (cnt == 3)
			return true;
		num /= 10;
	}
	return false;
}

int main()
{
	int N, cnt = 0, num = 666;

	scanf("%d", &N);

	while (cnt < N) {
		if (check(num++))
			cnt++;
	}
	num--;

	printf("%d\n", num);
}
