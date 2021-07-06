#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int>  b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> vec(N, { 0, 0});


	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vec[i] = { a, b };
	}
	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < N; i++)
		printf("%d %d\n", vec[i].first, vec[i].second);
}