#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

int main()
{
	int N, need_memory;
	scanf("%d %d", &N, &need_memory);

	vector<pair<int, int>> app(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &app[i].first);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &app[i].second);
	}

	sort(app.begin(), app.end(), compare);

	int index = app.size() - 1;

	for (int i = app.size() - 1; app[i].first >= need_memory; i--) {
		if (app[i].second < app[index].second)
			index = i;
	}

	vector<int> dp(100 * N + 1, 0);
	for (int appIndex = 0; appIndex < N; appIndex++) {
		for (int i = 100 * N; i >= app[appIndex].second; i--) {
			int cost = i - app[appIndex].second;
			dp[i] = max(dp[i], dp[cost] + app[appIndex].first);
		}
	}
	int mincost = 0;
	while (dp[mincost++] < need_memory);
	mincost--;
	printf("%d", mincost);
}