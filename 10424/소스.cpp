#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;

	scanf("%d", &N);

	vector<pair<int, int>> vec(N, { 0,0 });

	for (int i = 0; i < N; i++) {
		scanf("%d", &vec[i].first);
		vec[i].second = i+1;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		printf("%d\n",  vec[i].first- vec[i].second);
	}

	return 0;
}