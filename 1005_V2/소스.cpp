#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> mysort(vector<int>& timeForBuild, vector<vector<int>>& edge, vector<int>& edgeCnt, int N)
{
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (edgeCnt[i] == 0)
			que.push(i);
	}
	vector<int> result;
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		result.push_back(cur);

		for (int to : edge[cur]) {
			edgeCnt[to]--;
			if (edgeCnt[to] == 0)
				que.push(to);
		}
	}
	return result;
}
int main()
{
	int T;

	scanf("%d", &T);

	while (T--) {
		int N, K;
		scanf("%d %d", &N, &K);
		vector<int> timeForBuild(N+1, 0);
		vector<vector<int>> edge(N+1);
		vector<int> edgeCnt(N + 1, 0);
		for (int i = 1; i <= N; i++) {
			int input;
			scanf("%d", &input);
			timeForBuild[i] = input;
		}

		for (int i = 1; i <= K; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			edge[from].push_back(to);
			edgeCnt[to]++;
		}

		vector<int> result = mysort(timeForBuild, edge, edgeCnt, N);

		vector<int> totalTime(N + 1, 0);

		int W;
		scanf("%d", &W);
		for (int curIndex : result) {
			totalTime[curIndex] += timeForBuild[curIndex];
			if (curIndex == W)
				break;

			for (int to : edge[curIndex]) {
				if (totalTime[curIndex] > totalTime[to])
					totalTime[to] = totalTime[curIndex];
			}
		}
		printf("%d\n", totalTime[W]);
	}
}
