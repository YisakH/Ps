#include <cstdio>
#include <bitset>
#include <string>
#include <stack>
#define ZERO '0'

#define b2d(x, y, z) ((x<<2)|(y<<1)|z)

using namespace std;
char before[34];
char check;
bool isCon = true;

int isGarden(int p, int N, char dest[34], int start, int a, int b)
{
	int i, j, save1, save2, save3;

	if (start == N - 1)
	{
		if (((p >> b2d(a, b, check)) & 1) == dest[start])
		{
			isCon = false;
			return 0;
		}
	}

	for (j = 0; j < 8; j++)
	{
		if (((p >> j) & 1) != dest[start]) continue;

		if (start == 0) {
			check = (j >> 2) & 1;
			isGarden(p, N, dest, start + 1, (j >> 1) & 1, j & 1);
			check = 0;
		}
		else if (start == N - 2) {
			if (((p >> b2d(a, b, check)) & 1) == dest[start])
				isGarden(p, N, dest, start + 1, b, check);
		}
		else {
			for (i = 0; i < 2; i++) {
				if (((p >> b2d(a, b, i)) & 1) == dest[start]) {
					isGarden(p, N, dest, start + 1, b, i);
				}
			}
		}
		if (!isCon)
			return 0;
	}

	return 1;
}

int main()
{
	int N, p, i, j;
	char str[35], dest[34];

	while (fgets(str, 34, stdin)) {
		isCon = true;
		sscanf(str, "%d  %d %s", &p, &N, dest);
		for (i = 0; i < N; i++)
			dest[i] = dest[i] - '0';
		check = 0;
		if (isGarden(p, N, dest, 0, 0, 0))
			printf("GARDEN OF EDEN\n");
		else
			printf("REACHABLE\n");
	}
	return 0;
}