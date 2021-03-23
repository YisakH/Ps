#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<pair<int, int>>> vec;

int compare(pair<int, int> a, vector<vector<pair<int, int>>> b)
{
	
}
int main()
{
	int V, E, from, to, weight;
	scanf("%d %d", &V, &E);
	vec.assign(V + 1, {});
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		vec[from].push_back({ weight, to });
	}

	sort(vec.begin(), vec.end(), )
}