#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> linked_list;
vector<int> linked_size;
void wisang(int N)
{
	int i;
	for (i = 1; i <= N; i++)
		if (linked_size[i] == 0) {
			break;
		}

	while (i <= N) {
		printf("%d ", i);
		linked_size[i] = -1;

		for (int slice : linked_list[i])
			linked_size[slice]--;

		for (i = 1; i <= N; i++)
			if (linked_size[i] == 0) break;
	}


}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);
	
	linked_list.assign(N + 1, {});
	linked_size.assign(N + 1, 0);

	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		linked_list[a].push_back(b);
		linked_size[b]++;
	}

	wisang(N);
}