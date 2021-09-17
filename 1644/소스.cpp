#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
bool arr[4000001];
vector<int> sosu;
int cnt = 0;

void solve(int remain, int pos)
{
	if (pos < 0) return;

	int curval = remain - sosu[pos];

	if (curval > 0) {
		solve(curval, pos - 1);
	}
	else if (curval == 0) {
		cnt++;
	}
}

int main()
{
	int N;
	memset(arr, true, sizeof(arr));

	scanf("%d", &N);
	for (int i = 2; i <= sqrt(N); i++) {
		if (!arr[i]) continue;
		for (int j = 2; i * j <= N; j++) {
			arr[i * j] = false;
		}
	}

	for (int i = 2; i <= N; i++) {
		if (arr[i])
			sosu.push_back(i);
	}
	for (int start = sosu.size() - 1; start >= 0; start--)
		solve(N, start);
	

	printf("%d\n", cnt);

	return 0;
}