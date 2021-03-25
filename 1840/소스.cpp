#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int sdoku[9][9];
bool checklist[10];
bool continuebit = true;
bool solved = false;

typedef struct point
{
	int x;
	int y;
	int val;
}Point;

vector<Point> vec;

bool boxCheck(int y, int x)
{
	int standardX = (x / 3) * 3, standardY = (y / 3) * 3;
	for (int i = 0; i < 10; i++)
		checklist[i] = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sdoku[standardY + i][standardX + j] == 0)
				continue;
			else if (checklist[sdoku[standardY + i][standardX + j]] == false)
				checklist[sdoku[standardY + i][standardX + j]] = true;
			else
				return false;
		}
	}
	return true;
}

bool lineCheck(int y, int x)
{
	for (int i = 0; i < 10; i++)
		checklist[i] = false;

	for (int i = 0; i < 9; i++) {
		int val = sdoku[y][i];
		if (val == 0)
			continue;

		if (checklist[val] == true)
			return false;
		checklist[val] = true;
	}

	for (int i = 0; i < 10; i++)
		checklist[i] = false;
	for (int i = 0; i < 9; i++) {
		int val = sdoku[i][x];
		if (val == 0)
			continue;

		if (checklist[val] == true)
			return false;
		checklist[val] = true;
	}
	return true;
}

void cal(int y)
{
	int i = y, j = 0;

	while (i < 9 && sdoku[i][j] != 0)
	{
		j++;
		i += j / 9;
		j %= 9;
	}

	if (i >= 9) {
		continuebit = false;
		solved = true;
		return;
	}

	for (int key = 1; key <= 9; key++) {
		sdoku[i][j] = key;
		if (boxCheck(i, j) && lineCheck(i, j))
			cal(i);
		sdoku[i][j] = 0;
		if (!continuebit)
			return;
	}
}

void solve()
{
	for (int i = 0; i < 81; i++)
	{
		solved = false;
		continuebit = true;
		sdoku[vec[i].y][vec[i].x] = vec[i].val;
		cal(0);
		if (!solved) {
			printf("%d\n", i);
			return;
		}
	}
	printf("-1\n");
	return;
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int x, y, val;
			scanf("%d %d %d", &y, &x, &val);
			vec.push_back({ x, y, val });
		}
	solve();

	return 0;
}