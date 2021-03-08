#include <cstdio>
#include <queue>
using namespace std;
bool arr[1001][1001];
bool visited[1001];

int main()
{
	int N, M, i, node1, node2;
	queue<int> q;

	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++) {
		scanf("%d %d", &node1, &node2);
		arr[node1][node2] = arr[node2][node1] = true;
	}

	int cnt = 0;

	for (i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		cnt++;
		q.push(i);
		visited[i] = true;
		while (!q.empty()) {
			int j, pos = q.front();
			q.pop();
			for (j = i; j <= N; j++) {
				if (arr[pos][j] && !visited[j]) {
					q.push(j);
					visited[j] = true;
				}
			}
		}
	}
	printf("%d\n", cnt);
}