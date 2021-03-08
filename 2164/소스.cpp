#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v, cnt;
	int input, N, M, n, i, j, left, right, mid;

	scanf("%d", &N);
	v.assign(N, 0);
	for (n = 0; n < N; n++) {
		scanf("%d", &input);
		v[n] = input;
	}
	sort(v.begin(), v.end());
	for (i = 1, j=0; i < v.size(); i++) {
		if (v[i - 1] == v[i]) {

		}
	}
	scanf("%d", &M);
	lower
	for (i = 0; i < M; i++) {
		scanf("%d", &input);
		left = 0, right = v.size() - 1;
		mid = (left + right) / 2;
		while()
	}
}