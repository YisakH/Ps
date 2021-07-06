#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> mintime;
vector<int> time;
vector<vector<int>> list;
queue<int> que;

int BFS(int startPos) {
	int longest=0;
	que.push(startPos);
	mintime[startPos] = time[startPos];

	while (!que.empty()) {
		int pos = que.front();
		que.pop();

		int curTime = mintime[pos];

		int len = list[pos].size();
		for (int i = 0; i < len; i++) {
			int To = list[pos][i];

			if (curTime + time[To] > mintime[To]) {
				mintime[To] = curTime + time[To];
				longest = max(longest, mintime[To]);

				que.push(To);
			}
		}
	}
	return longest;
}
int main()
{
	int T;

	scanf("%d", &T);

	while (T--) {
		int N, K, X, Y, W;

		scanf("%d %d", &N, &K);

		time.assign(N+1, 0);
		list.assign(N + 1, vector<int>(0,0));
		mintime.assign(N + 1, 0);
		for (int i = 1; i <= N; i++)
			scanf("%d", &time[i]);
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &X, &Y);
			list[Y].push_back(X);
		}

		scanf("%d", &W);

		printf("%d\n", BFS(W));
	}
}
