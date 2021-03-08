#include <stdio.h>
#define N 10
int fib(int n)
{
	int arr[3] = { 0, 1, };
	int i;

	for (i = 2; i <= n; i++)
		arr[i % 3] = arr[(i - 1) % 3] + arr[(i - 2) % 3];

	return arr[n % 3];
}

int main()
{
	int i;

	printf("%d번째 피보나치 수는 %d\n", N, fib(N));
	return 0;
}