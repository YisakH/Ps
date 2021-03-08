#include <cstdio>
#include <queue>
#define KEY 1000000007
using namespace std;

int A[2][100001], B[100001];
int nextArr[2][100001];
bool Avalid = 1, nextValid = 1;

void solve(int N, int M)
{
	int i, j;
	int* before;

	for (i = 1; i <= M; i++) {
		before = nextArr[nextValid];

		for (j = 1; j <= N; j++) {
			A[Avalid][j] = A[!Avalid][j] + B[i];

			if (A[Avalid][j] % 7 == 0) {
				*before = nextArr[!nextValid][j];
			}
			else {
				*(before+1) = nextArr[!nextValid][j];
				before = &nextArr[nextValid][*before];
			}
		}
		if (nextArr[nextValid][0] != N) {
			nextValid = !nextValid;
			Avalid = !Avalid;
		}
	}
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[0][i]);
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &B[i]);
	}
	for (int i = 0; i <= N; i++) {
		nextArr[0][i] = nextArr[1][i] = i + 1;
	}

	solve(N, M);

	queue<int> q;
	int ptr = 0;
	while (ptr != N) {
		ptr = nextArr[nextValid][ptr];
		q.push(A[!Avalid][ptr]);
	}

	printf("%d\n", q.size());
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
}