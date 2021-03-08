#include <cstdio>
#include <vector>
#include <queue>

using namespace std;
vector<bool> v(1000001, true);
vector<int> before(1000001, 0);

int main()
{
	int N;
	scanf("%d", &N);
	while (N!=0) {
		v[1] = false;
		for (int i = 2; i <= 2*N; i++) {
			if (v[i] == true) {
				for (int j = 2; i * j <= 2*N; j++) {
					v[i * j] = false;
				}
			}
		}


		int cnt = 0;
		for (int i = N + 1; i <= 2 * N; i++) {
			if (v[i] == true)
				cnt++;
		}
		printf("%d\n", cnt);

		scanf("%d", &N);
	}
}