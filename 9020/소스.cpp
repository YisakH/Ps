#include <cstdio>
#include <vector>
using namespace std;
vector<bool> v(10001, true);

int main()
{
	int T;
	scanf("%d", &T);		
	for (int i = 2; i <= 10000; i++) {
		if (v[i] == true) {
			for (int j = 2; i * j <= 10000; j++) {
				v[i * j] = false;
			}
		}
	}

	while (T--)
	{
		int n, i;
		scanf("%d", &n);

		for (i = n / 2; i > 1; i--) {
			if (v[i] && v[n-i]) {
				printf("%d %d\n", i, n - i);
				break;
			}
		}
	}
}