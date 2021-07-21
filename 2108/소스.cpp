#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<short> vec(N);
	vector<int> cnt(8001, 0);
	for (int i = 0; i < N; i++) {
		scanf("%hd", &vec[i]);
	}
	sort(vec.begin(), vec.end());
	double sum = 0;
	int min = 10000, max = -10000;

	for (int i = 0; i < N; i++) {
		sum += vec[i];
		if (vec[i] < min)
			min = vec[i];
		if (vec[i] > max)
			max = vec[i];
		cnt[vec[i] + 4000]++;
	}
	int maxCnt = 0;
	for (int i = 0; i <= 8000; i++) {
		if (cnt[maxCnt] < cnt[i])
			maxCnt = i;
	}

	int sameCnt = 0;
	for (int i = 0; i <= 8000; i++) {
		if (cnt[i] == cnt[maxCnt]) {
			sameCnt++;
			if (sameCnt == 2) {
				maxCnt = i;
				break;
			}
		}
	}

	printf("%d\n", (int)round(sum / (double)N));
	printf("%d\n", vec[N / 2]);
	printf("%d\n", maxCnt-4000);
	printf("%d\n", max - min);
	return 0;
}