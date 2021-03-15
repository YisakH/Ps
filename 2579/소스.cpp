#include <cstdio>
#include <algorithm>
using namespace std;

int arr[10001];
int res[2][10001];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	res[0][1] = res[1][1] = arr[1];
	res[0][1] = arr[0] + arr[1];
	res[1][1] = arr[1];

	for (int i = 2; i <= N; i++) {
		res[0][i] = res[1][i - 1] + arr[i];
		res[1][i] = max(res[0][i - 2], res[1][i - 2]) + arr[i];
	}

	printf("%d\n", max(res[0][N], res[1][N]));
}