#include <cstdio>
#include <map>
#include <string>
#include <queue>
using namespace std;

int route[1000][4];

int main()
{
	int t, T, i, j, k, n, N, startt, endt;
	char start[40], end[40];
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		map<string, int> namelist;
		queue<int> q;
		j = 1;
		k = 0;
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			scanf("%s %s %d %d", start, end, startt, endt);
			if ((6 <= startt && startt < 18) || (6<endt && endt<=18))
				continue;
			if (namelist[start] <= 0)
				namelist.insert(make_pair(start, j++));
			if (namelist[end] <= 0)
				namelist.insert(make_pair(end, j++));

			route[k][0] = namelist[start];
			route[k][1] = namelist[end];
			route[k][2] = startt;
			route[k][3] = endt;
			k++;
		}
		scanf("%s %s", start, end);
		q.push(namelist[start]);
		
	}
}