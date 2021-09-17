#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int N;

	scanf("%d", &N);
	vector<int> inp(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &inp[i]);

	vector<int> vec;
	vec.push_back(inp[0]);
	for (int i = 1; i < N; i++) {
		vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), inp[i]);

		if (iter - vec.begin() < vec.size())
			vec[iter - vec.begin()] = inp[i];
		else
			vec.push_back(inp[i]);
	}

	printf("%d\n", vec.size());


}
