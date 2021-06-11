#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N, inp, sum=0;
	int result = -210000000;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &inp);

		if (sum > 0 && sum + inp < 0) {
			sum = 0;
			continue;
		}
		sum += inp;
		sum = max(sum, inp);

		result = max(result, sum);
	}
	printf("%d", result);
}