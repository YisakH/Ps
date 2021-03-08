#include <cstdio>
#include <vector>
#include <queue>
#define NOROOT 100000000

using namespace std;
int main()
{
	int V, E, start, u, v, w, i;

	scanf("%d %d", &V, &E);
	vector<pair<int, int>> *vec;
	vec = new vector<pair<int, int>>[V + 1];

	scanf("%d", &start);

	for (i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);
		vec[u].push_back(make_pair(w, v));
	}

	vector<int> dist(V + 1, NOROOT);
	vector<bool> visit(V + 1, false);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push(make_pair(0, start));
	int cur, weight, before;
	before = start;
	while (!pq.empty()) {
		cur = pq.top().second;
		weight = pq.top().first;
		pq.pop();
		if (visit[cur])
			continue;
		visit[cur] = true;
		
		
		for (i = 0; i < vec[cur].size(); i++) {
			int next = vec[cur][i].second, nextW = vec[cur][i].first;

			if (dist[cur] + nextW < dist[next]) {
				dist[next] = dist[cur] + nextW;
			}
			if (!visit[next])
				pq.push(make_pair(nextW + dist[cur], next));
		}
	}
	for (i = 1; i <= V; i++)
		if (dist[i] == NOROOT)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
}