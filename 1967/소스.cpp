#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<int> leaf;
vector<bool> visit;


int main()
{
	int N, maxcount = 0;
	scanf("%d", &N);

	tree.assign(N + 1, {});

	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back({ b, c });
		tree[b].push_back({ a, c });
	}

	for (int i = 1; i <= N; i++) {
		if (tree[i].size() < 2)
			leaf.push_back(i);
	}

	for (int leaf_pos = 0; leaf_pos < leaf.size(); leaf_pos++) {
		queue<pair<int, int>> que;
		visit.assign(N + 1, false);
		
		que.push({ leaf[leaf_pos], 0 });
		visit[leaf[leaf_pos]] = true;

		while (!que.empty()) {
			int pos = que.front().first, weight = que.front().second;
			que.pop();
			int cnt=0;
			for (int j = 0; j < tree[pos].size(); j++) {
				int to = tree[pos][j].first;
				if (!visit[to]) {
					que.push({ to, tree[pos][j].second + weight });
					visit[to] = true;
					cnt++;
				}
			}

			if (cnt == 0) {
				maxcount = max(maxcount, weight);
			}
		}
	}
	printf("%d", maxcount);
	return 0;
}