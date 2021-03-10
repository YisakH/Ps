#include <cstdio>
int arr[2][10] = { { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, };

int main()
{
	int N;
	bool key = true;
	scanf("%d", &N);

	for (int i = 1; i < N; i++)
	{
		for (int lastnum = 0; lastnum <= 8; lastnum++)
		{
			arr[key][lastnum] = arr[!key][lastnum + 1];
		}
		arr[key][9] = 0;

		for (int lastnum = 1; lastnum <= 9; lastnum++)
		{
			arr[key][lastnum] = (arr[key][lastnum] + arr[!key][lastnum - 1]) % 1000000000;
		}
		key = !key;
	}

	int sum = 0;
	for (int i = 0; i <= 9; i++)
	{
		sum = (sum + arr[!key][i]) % 1000000000;
	}
	printf("%d\n", sum);
}