#include <cstdio>
#include <vector>
using namespace std;
int N, M;
vector<int> vec;
void makeseq(int startnum, int m)
{
	if (m == M) {
		for (int i = 0; i < vec.size(); i++)
			printf("%d ", vec[i]);
		printf("\n");
		return;
	}

	for (int i = startnum; i <= N; i++)
	{
		vec.push_back(i);
		makeseq(i + 1, m + 1);
		vec.resize(vec.size() - 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	makeseq(1, 0);
}