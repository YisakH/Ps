#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int N, M, n, m, Bcnt = 0, Wcnt = 0, totalcount =2500, i, j;
	char check[52][52];
	scanf("%d %d", &N, &M);
	fgets(check[0], 51, stdin);

	for (i = 0; i < N; i++) {
		scanf("%s", check[i]);
	}
	for (n = 0; n <= N - 8; n++) {
		for(m=0; m<=M-8; m++){
			Wcnt = 0;
			Bcnt = 0;
			for (i = n; i < n+8; i++)
			{
				for (j = m; j < m+8; j++) {
					if ((i + j) % 2 == 0) {
						if (check[i][j] == 'B')
							Wcnt++;
						else if(check[i])
							Bcnt++;
					}
					else {
						if (check[i][j] == 'B')
							Bcnt++;
						else
							Wcnt++;
					}
				}
			}
			totalcount = min(totalcount, Bcnt);
			totalcount = min(totalcount, Wcnt);
		}
	}
	printf("%d\n", totalcount);

	return 0;
}