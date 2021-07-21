#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	vector<pair<int, int>> vec(N, {0, 0});
	vector<int> maxW_backpack(K);
	for (int i = 0; i < N; i++) {
		int M, V;
		scanf("%d %d", &M, &V);
		vec[i] = { M, V };
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &maxW_backpack[i]);
	}
	sort(vec.begin(), vec.end());
	sort(maxW_backpack.begin(), maxW_backpack.end());

	long long answer = 0;
	int pointer = 0;
	priority_queue<int> pq;
	for (int i = 0; i < K; i++) {

		for (; pointer < vec.size() && vec[pointer].first <= maxW_backpack[i]; pointer++)
			pq.push(vec[pointer].second);

		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", answer);
}