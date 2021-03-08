#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[100001];

int main()
{
	int N, K, i, tmp;
	memset(visited, sizeof(visited), false);

	scanf("%d %d", &N, &K);
	tmp = max(N, K);
	N = min(N, K);
	K = tmp;

	pq.push({ 0, N });
	visited[N] = true;

	while (!pq.empty())
	{
		pair<int, int> point = pq.top();
		pq.pop();
		if (point.second == K) {
			printf("%d\n", point.first);
			break;
		}
		if (point.second <= 50000 && !visited[point.second * 2]) {
			pq.push({ point.first, point.second * 2 });
			visited[point.second * 2] = true;
		}
		if (point.second > 1 && !visited[point.second - 1]) {
			pq.push({ point.first + 1, point.second - 1 });
			visited[point.second - 1] = true;
		}

		if (point.second <= 100000 && !visited[point.second + 1]) {
			pq.push({ point.first + 1, point.second + 1 });
			visited[point.second + 1] = true;
		}

	}
}