#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int N, K;

	scanf("%d %d", &N, &K);
	vector<int> list	(N + 1, 0);
	vector<int> next(N + 1, 0);
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		list[i] = next[i] = i + 1;
	}
	next[N - 1] = 0;
	
	int cur = N-1, before = 0;
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < K; j++) {
			before = cur;
			cur = next[cur];
		}
		answer.push_back(list[cur]);

		next[before] = next[cur];
	}

	printf("<");
	for (int i = 0; i < N - 1; i++)
		printf("%d, ", answer[i]);
	printf("%d>", answer[N - 1]);


}