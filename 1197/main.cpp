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

vector<int> root;
priority_queue<edge, vector<edge>, compare> q;



bool isSame(int a, int b)
{
	return root[a] == root[b];
}


void add(int nodeA, int nodeB, int size)
{
	int rootA = root[nodeA];

	for (int i = 0; i < size; i++)
	{
		if (root[i] == root[nodeB])
			root[i] = rootA;
	}
}

int main()
{
	int V, E, from, to, weight;
	scanf("%d %d", &V, &E);

	root.assign(V + 1, 0);
	for (int i = 0; i <= V; i++)
		root[i] = i;

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		q.push({ from, to, weight });
	}

	int cnt = 0, i = 0, sum = 0;

	while (cnt < V - 1 && !q.empty())
	{
		Edge e = q.top();
		q.pop();

		if (isSame(e.from, e.dest))
			continue;

		add(e.from, e.dest, V);

		sum += e.weight;
		cnt++;
		i++;
	}

	printf("%d\n", sum);

	return 0;
}