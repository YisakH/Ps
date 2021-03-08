#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int i, N, result=0;
	int* arr;

	scanf("%d", &N);
	arr = new int[N + 1];

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, &arr[N]);

	for (i = 0; i < N; i++)
	{
		result = result + arr[i] * (N - i);
	}
	printf("%d\n", result);
}