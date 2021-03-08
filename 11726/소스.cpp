#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);

	vector<int> vec(n + 1, 0);
	vec[0] = 1;
	vec[1] = 1;

	for (i = 2; i <= n; i++)
		vec[i] = (vec[i - 2] + vec[i - 1])%10007;

	printf("%d\n", vec[n]);
}