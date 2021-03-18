#include <cstdio>

int main()
{
	int T, A, B, saveA, saveB;

	scanf("%d", &T);

	while (T--)
	{

		scanf("%d %d", &A, &B);
		saveA = A;
		saveB = B;

		while (B != 0)
		{
			int tmp = B;
			B = A % B;
			A = tmp;
		}

		printf("%d\n", saveA * saveB / A);
	}
}