#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int input[5001];
int N, m = 0, p = 0;


void solve()
{
	long long resultL = input[0], resultM = input[1], resultR = input[2];

	for (int left = 0; left < N - 2; left++) {
		for (int mid = left + 1; mid < N - 1; mid++) {
			long long halfval = input[left] + input[mid];

			int seqL=mid+1, seqR=N-1, seqM;
			while (seqL <= seqR) {
				seqM = (seqL + seqR) / 2;

				if (abs(halfval + input[seqM]) < abs(resultR + resultL + resultM)) {
					resultR = input[seqM];
					resultM = input[mid];
					resultL = input[left];
				}

				if (input[seqM] + halfval < 0) {
					seqL = seqM + 1;
				}
				else {
					seqR = seqM - 1;
				}
			}

		}
	}
	printf("%lld %lld %lld\n", resultL, resultM, resultR);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}
	m--, p--;

	sort(input, &input[N]);

	solve();

}