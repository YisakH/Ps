#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int solve(int N)
{
	int i, j;
	vector<int> cnt(N, 0);

	for (i = 0; i < N; i++) {
		if (cnt[i] == 0)
			cnt[i] = 1;
		for (j = i + 1; j < N; j++) {
			if (v[i].second < v[j].second && cnt[i] + 1 > cnt[j])
				cnt[j] = cnt[i] + 1;
		}
	}
	int max = 0;
	for (i = 0; i < N; i++) {
		if (max < cnt[i])
			max = cnt[i];
	}
	return N - max;
}

int main()
{
	int N;
	scanf("%d", &N);

	v.assign(N, {});

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[i] = { a, b };
	}

	sort(v.begin(), v.end(), compare);

	printf("%d\n", solve(N));
	return 0;
}