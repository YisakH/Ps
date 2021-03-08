#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> posi, nega;

int main()
{
	int N, i, j;
	scanf("%d", &N);
	posi.assign(N + 1, 0);
	nega.assign(N + 1, 0);

	for (i = 0; i < N; i++)
		scanf("%d", &posi[i]);
	sort(posi.begin(), posi.end(), greater<int>());
	for (i = posi.size() -1, j=0; posi[i] < 0; i--) {
		nega[j++] = posi[i];
	}
	posi.resize(i);
	nega.resize(j);
	i = j = 0;
	int sum_min = 2100000000, mnum, pnum;

	while (i < posi.size() && j < nega.size()) {
		if (abs(posi[i] + nega[j]) < sum_min) {
			sum_min = abs(posi[i] + nega[j]);
			mnum = nega[j];
			pnum = posi[i];
		}
		if (posi[i] > -1 * nega[j])
			i++;
		else
			j++;
	}
	if (posi.size() >= 2 && posi[posi.size() - 1] + posi[posi.size() - 2] < sum_min) {
		sum_min = posi[posi.size() - 1] + posi[posi.size() - 2];
		mnum = posi[posi.size() - 1];
		pnum = posi[posi.size() - 2];
	}
	if (nega.size() >= 2 && abs(nega[nega.size() - 1] + nega[nega.size() - 2]) < sum_min) {
		sum_min = abs(nega[nega.size() - 1] + nega[nega.size() - 2]);
		mnum = nega[nega.size() - 2];
		pnum = nega[nega.size() - 1];
	}
	printf("%d %d\n", mnum, pnum);
}