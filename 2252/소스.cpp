#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> vec;
int chasu[50000];
queue<int> que;

int main()
{
	int N, M, i;

	scanf("%d %d", &N, &M);
	vec.assign(N + 1, {});

	for (i = 0; i < M; i++) {
		int stu1, stu2;
		scanf("%d %d", &stu1, &stu2);
		vec[stu1].push_back(stu2);
	}
	for (i = 1; i <= N; i++) {
		chasu[i] = vec[i].size();
		if (chasu[i] == 0)
			que.push(i);
	}

	while (!que.empty()) {
		int pos = que.front();
		que.pop();
		
		for (int j = 1; j <= N; j++) {

		}
	}
}
