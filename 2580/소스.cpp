#include <cstdio>

int sdoku[9][9];
bool checklist[10];
bool continuebit = true;
bool boxCheck(int y, int x)
{
	int standardX = (x / 3)*3, standardY = (y / 3)*3;
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
	int i=y, j=0;
	
	while (i < 9 && sdoku[i][j] != 0)
	{
		j++;
		i += j / 9;
		j %= 9;
	}

	if (i >= 9) {
		continuebit = false;
		return;
	}

	for (int key = 1; key <= 9; key++) {
		sdoku[i][j] = key;
		if (boxCheck(i, j) && lineCheck(i, j))
			cal(i);
		if (!continuebit)
			return;
		sdoku[i][j] = 0;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &sdoku[i][j]);
	cal(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", sdoku[i][j]);
		printf("\n");
	}
	return 0;
}