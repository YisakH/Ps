#include <cstdio>

using namespace std;

char arr[8][9];

bool garoCheck(int startY, int startX, int N) {
	int endX = startX + N - 1;

	while (startX <= endX) {
		if (arr[startY][startX] != arr[startY][endX])
			return false;
		startX++;
		endX--;
	}
	return true;
}
bool seroCheck(int startY, int startX, int N) {
	int endY = startY + N - 1;

	while (startY <= endY) {
		if (arr[startY][startX] != arr[endY][startX])
			return false;
		startY++;
		endY--;
	}
	return true;
}
int main()
{
	int cnt, N;


	for (int k = 1; k <= 10; k++) {
		scanf("%d", &N);
		cnt = 0;

		for (int i = 0; i < 8; i++)
			scanf("%s", arr[i]);

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - N + 1; j++) {
				cnt += garoCheck(i, j, N);
			}
		}
		for (int i = 0; i < 8 - N + 1; i++) {
			for (int j = 0; j < 8; j++) {
				cnt += seroCheck(i, j, N);
			}
		}

		printf("#%d %d\n", k, cnt);
	}
}
