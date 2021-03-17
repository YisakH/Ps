#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int B[500];
vector<pair<int, int>> v;

int compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
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
		B[b] = 1;
	}

	sort(v.begin(), v.end(), compare);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (B[i] == 1)
			cnt++;
		B[i] = cnt;
	}

}