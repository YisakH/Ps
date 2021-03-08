#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int arr[100001];
queue<int> q;
int main()
{
	int N, K, i, val;
	scanf("%d %d", &N, &K);
	val = N;
	while (val != K)
	{
		if (val > 0 && arr[val - 1] == 0) {
			q.push(val - 1);
			arr[val - 1] = arr[val] + 1;
		}
		if (val < 100000 && arr[val + 1] == 0) {
			q.push(val + 1);
			arr[val + 1] = arr[val] + 1;
		}
		if (val <= 50000 && arr[val * 2] == 0) {
			q.push(val * 2);
			arr[val * 2] = arr[val] + 1;
		}
		val = q.front();
		q.pop();
	}
	printf("%d\n", arr[K]);
	return 0;
}