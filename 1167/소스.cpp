#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<pair<int, short>>> tree;
int max_length = 0, max_pos = -1;

void dfs(int pos, int w, int prev)
{
	if (max_length < w) {
		max_length = w;
		max_pos = pos;
	}

	for (int i = 0; i < tree[pos].size(); i++) {
		int next = tree[pos][i].first, pos_weight = tree[pos][i].second;
		if (next != prev) {
			dfs(next, w + pos_weight, pos);
		}
	}
}


int main()
{
	int N;
	scanf("%d", &N);
	tree.assign(N + 1, {});

	for (int i = 1; i <= N; i++) {
		int ver, wei, start;
		scanf("%d", &start);
		scanf("%d", &ver);

		while (ver != -1) {
			scanf("%d", &wei);
			tree[start].push_back({ ver, wei });
			scanf("%d", &ver);
		}
	}
	dfs(1, 0, -1);
	max_length = 0;
	dfs(max_pos, 0, -1);

	printf("%d\n", max_length);

	return 0;
}