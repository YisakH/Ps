#include <cstdio>
#include <queue>
#define toint(a, b, c, d) (a*1000+b*100+c*10+d)
using namespace std;

int main()
{
	int N, n, a, b, c, d, first, last, i, num, tmp;
	int step[10001];
	bool ban[10001];
	queue<int> q;

	scanf("%d", &N);
	while (N)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		first = toint(a, b, c, d);
		scanf("%d %d %d %d", &a, &b, &c, &d);
		last = toint(a, b, c, d);

		memset(step, 0, sizeof(step));

		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			ban[toint(a, b, c, d)] == 1;
		}
		q.push(first);

		while (!q.empty())
		{
			num = q.front();
			q.pop();

			tmp = (num + 1000) % 10000;
			if (!ban[tmp]) {
				q.push(tmp);
				step[tmp] = step[first] + 1;
			}
			

		}

		scanf("%d", &N);
	}
}