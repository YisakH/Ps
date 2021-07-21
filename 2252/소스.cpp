#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> linked(N+1);
	vector<int> linkCnt(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);

		linked[from].push_back(to);
		linkCnt[to]++;
	}

	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (linkCnt[i] == 0) {
			que.push(i);
		}
	}

	vector<int> answer;
	while (!que.empty()) {
		int from = que.front();
		que.pop();
		
		answer.push_back(from);

		for (int to : linked[from]) {
			linkCnt[to]--;

			if (linkCnt[to] == 0)
				que.push(to);
		}
	}
	for (int num : answer) {
		printf("%d ", num);
	}
	return 0;
}