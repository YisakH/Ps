#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int N, M, i;
	vector<bool> v;
	cin >> N;
	cin >> M;
	v.assign(M + 1, true);
	v[1] = false;

	for (i = 2; i <= M; i++) {
		if (v[i] == true) {
			for (int j = 2; j * i <= M; j++) {
				v[j * i] = false;
			}
		}
	}
	int min = 1000000, sum = 0;
	for (i = N; i <= M; i++)
		if (v[i] == true) {
			sum += i;
			if (i < min)
				min = i;
		}

	if (sum > 0)
		printf("%d\n%d\n", sum, min);
	else
		printf("-1\n");
}