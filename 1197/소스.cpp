#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef struct edge
{
	int from;
	int dest;
	int weight;
}Edge;

struct compare {
	bool operator()(Edge a, Edge b) {
		if (a.weight != b.weight)
			return a.weight >= b.weight;
		else
			return 0;
	}
};

vector<int> check;
priority_queue<edge, vector<edge>, compare> q;



bool isSame(int a, int b)
{
	while (check[a] != a) {
		a = check[a];
	}
	while (check[b] != b) {
		b = check[b];
	}
	return a == b;
}
int getRoot(int a)
{
	while (check[a] != a)
		a = check[a];
	return a;
}


int main()
{
	int V, E, from, to, weight;
	scanf("%d %d", &V, &E);

	check.assign(V + 1, 0);
	for (int i = 0; i <= V; i++)
		check[i] = i;

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		q.push({ from, to, weight });
	}

	int cnt = 0, i = 0, sum = 0;

	while (cnt < V-1 && !q.empty())
	{
		Edge e = q.top();
		q.pop();

		if (isSame(e.from, e.dest))
			continue;

		check[getRoot(e.from)] = getRoot(e.dest);

		sum += e.weight;
		cnt++;
		i++;
	}

	printf("%d\n", sum);
}