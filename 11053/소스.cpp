#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct point
{
	int before;
	int length;
}Point;
int arr[1001];
int length[1001];
int main()
{
	int i, j, N, ans=1;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < N; i++)
	{
		int maxlen = 1;
		for (j = 0; j < i; j++)
		{
			if (length[j] >= maxlen && arr[j] < arr[i])
				maxlen = length[j] + 1;
		}
		length[i] = maxlen;
	}

	for (i = 0; i < N; i++)
		ans = max(ans, length[i]);

	printf("%d\n", ans);
}