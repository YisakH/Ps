#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector<pair<int, int>> vec;// vector[i].first == 거리, second == 이전 수
int main()
{
	int N;
	scanf("%d", &N);
	vec.assign(N + 1, { 2000000, 0 });

	vec[N].first = 0;
	vec[N].second = -1;
	for (int i = N; i >= 1; i--) {
		if (i % 3 == 0 && vec[i/3].first > vec[i].first + 1) {
			vec[i / 3].first = vec[i].first + 1;
			vec[i / 3].second = i;
		}
		if (i % 2 == 0 && vec[i / 2].first > vec[i].first + 1) {
			vec[i / 2].first = vec[i].first + 1;
			vec[i / 2].second = i;
		}
		if (vec[i - 1].first > vec[i].first + 1) {
			vec[i - 1].first = vec[i].first + 1;
			vec[i - 1].second = i;
		}
	}
	stack<int> st;
	int pos = 1;
	while (vec[pos].second != -1) {
		st.push(pos);
		pos = vec[pos].second;
	}
	printf("%d\n", vec[1].first);
	printf("%d ", N);
	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}

}