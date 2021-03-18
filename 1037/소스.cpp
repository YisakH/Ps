#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int arr[50];
	int cnt;

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, &arr[cnt]);

	printf("%d\n", arr[0] * arr[cnt - 1]);
}