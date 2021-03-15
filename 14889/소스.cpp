#include <cstdio>
#include <cmath>

bool team[20];
int arr[21][21];
int minScore = 2100000000;

int score(int N)
{
	int aScore=0, bScore=0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (team[i] && team[j])
				aScore += arr[i][j] + arr[j][i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (!team[i] && !team[j])
				bScore += arr[i][j] + arr[j][i];
		}
	}

	return abs(aScore - bScore);
}

void devideteam(int N, int cur, int start)
{
	if (N/2 == cur) {
		int res = score(N);
		if (res < minScore)
			minScore = res;
	}

	for (int i = start; i < N; i++)
	{
		if (team[i] == false)
		{
			team[i] = true;
			devideteam(N, cur + 1, i + 1);
			team[i] = false;
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	devideteam(N, 0, 0);

	printf("%d", minScore);
}