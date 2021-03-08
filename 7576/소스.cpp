#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
typedef struct ik
{
	int ypos;
	int xpos;
}Ik;
int arr[1001][1001];

int main()
{
	int M, N, i, j, cnt = 0, maxcnt = 0;
	Ik visit;
	queue<Ik> q;
	scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push(Ik{ i, j });
			}		
		}
	while (!q.empty())
	{
		visit = q.front();
		q.pop();
		cnt = arr[visit.ypos][visit.xpos];
		maxcnt = max(cnt, maxcnt);

		if (visit.ypos > 0 && arr[visit.ypos - 1][visit.xpos] == 0) {
			arr[visit.ypos - 1][visit.xpos] = cnt + 1;
			q.push(Ik{ visit.ypos - 1, visit.xpos });
		}
		if (visit.ypos+1 < N && arr[visit.ypos + 1][visit.xpos] == 0) {
			arr[visit.ypos + 1][visit.xpos] = cnt + 1;
			q.push(Ik{ visit.ypos + 1, visit.xpos });
		}
		if (visit.xpos > 0 && arr[visit.ypos][visit.xpos -1] == 0) {
			arr[visit.ypos][visit.xpos - 1] = cnt + 1;
			q.push(Ik{ visit.ypos, visit.xpos - 1 });
		}
		if (visit.xpos + 1 < M && arr[visit.ypos][visit.xpos + 1] == 0) {
			arr[visit.ypos][visit.xpos + 1] = cnt + 1;
			q.push(Ik{ visit.ypos, visit.xpos + 1 });
		}
	}
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
			if (arr[i][j] == 0) {
				printf("-1\n");
				return 0;
			}

	printf("%d\n", maxcnt-1);
}