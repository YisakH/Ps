#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 210000000
vector<pair<int, int>> vec[501];
vector<pair<int, int>>::iterator iter;
int dist[501];

void find(int N)
{
	int start = 1, run_cnt, i, j;

	for (i = 0; i < 501; i++)
		dist[i] = MAX;
	dist[start] = 0;
	for (run_cnt = 0; run_cnt < N; run_cnt++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (iter=vec[i].begin(); iter!=vec[i].end(); iter++)
			{
				if (dist[iter->first] > dist[i] + iter->second)
					dist[iter->first] = dist[i] + iter->second;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (iter = vec[i].begin(); iter != vec[i].end(); iter++)
		{
			if (dist[iter->first] > dist[i] + iter->second) {
				printf("YES\n");
				return;
			}
		}
	}
	printf("NO\n");
}

int main()
{
	int s, e, t, tc, i, j, N, M, W;

	scanf("%d", &tc);
	while (tc--)
	{
		for (i = 0; i < 501; i++)
			vec[i].clear();
		scanf("%d %d %d", &N, &M, &W);
		for (i = 0; i < M; i++) {
			scanf("%d %d %d", &s, &e, &t);

			for (j = 0; j < vec[s].size(); j++)
				if (vec[s][j].first == e)
					break;
			if (j == vec[s].size()) {
				vec[s].push_back({ e, t });
				vec[e].push_back({ s, t });
			}
			else if(vec[s][j].second > t){
				vec[s][j].second = t;

				for (iter = vec[e].begin(); iter->first != s; iter++);
				iter->second = t;
			}
		}
		for (i = 0; i < W; i++) {
			scanf("%d %d %d", &s, &e, &t);
			for (iter = vec[s].begin();iter != vec[s].end() && iter->first != e ; iter++);
			
			if (iter == vec[s].end())
				vec[s].push_back({ e, -t });
			else if (iter->second > -t)
				iter->second = -t;
		}

		find(N);

	}
}