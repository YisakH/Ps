#include <cstdio>
#include <deque>
using namespace std;

bool isUsed[9];
deque<int> deq;
deque<int>:: iterator  iter;
void cal(int N, int M)
{
	if (M == 0) {
		for (iter = deq.begin(); iter != deq.end(); iter++)
			printf("%d ", *iter);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (isUsed[i] == false) {
			isUsed[i] = true;
			deq.push_back(i);

			cal(N, M - 1);

			deq.pop_back();
			isUsed[i] = false;
		}
	}
}

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	cal(N, M);
	return 0;
}