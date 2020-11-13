#include <cstdio>
#include <map>
#include <string>
#include <queue>
using namespace std;

int route[1002][5];
int howtime[102];

int main()
{
	int t, T, i, j, numE, n, N, startt, endt, tmp1, tmp2, point, time, totaltime;
	char start[40], end[40];
	scanf("%d", &T);

	for (t = 1; t <= T; t++)
	{
		map<string, int> namelist;
		queue<int> q;
		
		j = 1;
		numE = 0;

		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			for (j = 0; j < 1002; j++)
				route[j][5] = 10000000;
			memset(howtime, 0, sizeof(howtime));

			scanf("%s %s %d %d", start, end, startt, endt);
			if ((6 <= startt && startt < 18) || (6<endt && endt<=18))
				continue;
			if (namelist[start] <= 0)
				namelist.insert(make_pair(start, j++));
			if (namelist[end] <= 0)
				namelist.insert(make_pair(end, j++));
			startt = (startt + 6) % 24;
			endt = (endt + 6) % 24;

			route[numE][0] = namelist[start];
			route[numE][1] = namelist[end];
			route[numE][2] = startt;
			route[numE][3] = endt;
			numE++;
		}
		scanf("%s %s", start, end);
		q.push(namelist[start]);
		time = 0;
		totaltime = 0;
		// 출발시간 0시, 도착은 12시 전에, 매 18시에 피 먹어야됨
		while (!q.empty()) {
			point = q.front();
			q.pop();
			for (i = 0; i < numE; i++)
			{
				if (route[i][0] != point)continue; // 출발지가 현재 위치가 아니라면
				if (route[i][2] < time) continue; // 현재 차가 이미 출발했다면
				tmp1 = totaltime;
				tmp2 = time;
				totaltime += route[i][3] - time;
				time = route[i][3];

				if (howtime[route[i][1]] == 0 || totaltime < howtime[route[i][1]]) {
					howtime[route[i][1]] = totaltime;
					q.push(i);
				}

			}

		}
		
	}
}