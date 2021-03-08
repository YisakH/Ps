#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> vec;
vector<int> output;
bool used[10];
int N, M;

void makeseq(int m)
{
	if (m == M) {
		for (int i = 0; i < output.size(); i++)
			printf("%d ", output[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (used[i]) continue;
		output.push_back(vec[i]);
		used[i] = true;
		makeseq(m + 1);
		output.resize(output.size() - 1);
		used[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	vec.assign(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &vec[i]);

	sort(vec.begin(), vec.end());

	makeseq(0);
}