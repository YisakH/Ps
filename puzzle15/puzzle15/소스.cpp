#include <cstdio>
#include <stack>
#include <cmath>

using namespace std;

//int minimum[][] = {
//	{}
//}

const int finalstate[24] = { 0,3,4,3,0,5,6,5,0,1,2,1,0,7,8,7,0,9, 10,9,0,1,2,1 };
int shift[5] = { 0, };
int curstate[24];
int apoint, bpoint;
bool isSolved = false;
stack<int> s;

void printstack()
{
	stack<int> tmp;
	while (!s.empty()) {
		tmp.push(s.top());
		s.pop();
	}
	while (!tmp.empty()) {
		printf("%d", tmp.top());
		tmp.pop();
	}
}

void check()
{
	int i, j;
	j = 0;
	for (i = 0; i < 24; i++)
	{
		if (i < 12) {
			if ((curstate[(apoint + i) % 12]) != finalstate[i])
				return;
		}
		else {
			if (curstate[((bpoint + j++) % 12) + 12] != finalstate[i])
				return;
		}
	}
	isSolved = true;
}

void move(int n)
{
	switch (n)
	{
	case 1:
		apoint = (apoint + 10) % 12;
		curstate[12 + ((bpoint + 9) % 12)] = curstate[(apoint + 9) % 12];
		curstate[12 + ((bpoint + 10) % 12)] = curstate[(apoint + 10) % 12];
		curstate[12 + ((bpoint + 11) % 12)] = curstate[(apoint + 11) % 12];
		break;
	case 2:
		bpoint = (bpoint + 2) % 12;
		curstate[(apoint + 9) % 12] = curstate[12 + ((bpoint + 9) % 12)];
		curstate[(apoint + 10) % 12] = curstate[12 + ((bpoint + 10) % 12)];
		curstate[(apoint + 11) % 12] = curstate[12 + ((bpoint + 11) % 12)];
		break;
	case 3:
		apoint = (apoint + 2) % 12;
		curstate[12 + ((bpoint + 9) % 12)] = curstate[(apoint + 9) % 12];
		curstate[12 + ((bpoint + 10) % 12)] = curstate[(apoint + 10) % 12];
		curstate[12 + ((bpoint + 11) % 12)] = curstate[(apoint + 11) % 12];
		break;
	case 4:
		bpoint = (bpoint + 10) % 12;
		curstate[(apoint + 9) % 12] = curstate[12 + ((bpoint + 9) % 12)];
		curstate[(apoint + 10) % 12] = curstate[12 + ((bpoint + 10) % 12)];
		curstate[(apoint + 11) % 12] = curstate[12 + ((bpoint + 11) % 12)];
		break;
	}
}

void cal(int n)
{
	static int depth = 0;
	int i, j;

	check();
	if (isSolved) {
		return;
	}

	if (depth == n)
		return;

	for (i = 1; i <= 4; i++)
	{
		if (shift[i] == 4 || shift[((i - 1) + 2) % 4])
			continue;
		if (shift[i] == 0)
		{
			for (j = 1; j <= 4; j++)
				shift[j] = 0;
		}
		shift[i]++;

		s.push(i);
		move(i);
		depth++;
		cal(n);
		if (isSolved)
			return;
		depth--;
		shift[i]--;
		move((i + 1) % 4);
		if (!s.empty())
			s.pop();
	}
}

int main()
{
	int t, T, i, j, max_depth;

	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		for (i = 0; i < 24; i++)
			scanf("%d", &curstate[i]);

		isSolved = false;

		for (max_depth = 0; max_depth <= 16; max_depth++) {
			if (isSolved)
				break;
			for (j = 1; j <= 4; j++)
				shift[j] == 0;
			cal(max_depth);
		}

		if (isSolved) {
			if (max_depth == 1)
				printf("PUZZLE ALREADY SOLVED\n");
			else
				printstack();
		}
		else {
			printf("NO SOLUTION WAS FOUND IN 16 STEPS\n");
		}

	/*	for (i = 0; i < 12; i++)
			printf("%d ", curstate[(apoint + i) % 12]);
		for (i = 0; i < 12; i++)
			printf("%d ", curstate[((bpoint + i) % 12) + 12]);

		printf("\n");
	*/}
}