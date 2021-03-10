#include <cstdio>
#include <deque>
using namespace std;

deque<int> deq;
deque<int>::iterator  iter;
void cal(int N, int M, int start)
{
	if (M == 0) {
		for (iter = deq.begin(); iter != deq.end(); iter++)
			printf("%d ", *iter);
		printf("\n");
		return;
	}

	for (int i = start; i <= N; i++) {
		deq.push_back(i);

		cal(N, M - 1, i);

		deq.pop_back();

	}
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	cal(N, M, 1);
	return 0;
}