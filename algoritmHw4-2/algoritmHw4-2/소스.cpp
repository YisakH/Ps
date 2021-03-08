#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define NODISTANCE 9999

int** D, **Pd, **Pf, ** W;

void printArr(int N)
{
	int i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			printf("%5d", W[i][j]);
		printf("\n");
	}
	printf("\n");
}
void copy(int N, int*** W, int*** dest)
{
	int i, j;

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
			(*dest)[i][j] = (*W)[i][j];
	}
}
void makegraph(int N)
{
	srand((unsigned)time(NULL));
	D = new int* [N+1];
	W = new int* [N + 1];
	Pd = new int* [N + 1];
	Pf = new int* [N + 1];

	for (int i = 0; i <= N; i++)
	{
		Pd[i] = new int[N + 1];
		Pf[i] = new int[N + 1];
		D[i] = new int[N + 1];
		W[i] = new int[N + 1];
	}
}
void randgenerate(int N, double density)
{
	int i, j, randnum1, randnum2;
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			W[i][j] = (rand() % ((rand() % 999) + 1)) + 1;
		}
	}
	for (i = 0; i < (int)(N*N *density); i++)
	{
		randnum1 = rand() % N;
		randnum2 = rand() % N;
		W[randnum1][randnum2] = NODISTANCE;
		W[randnum2][randnum1] = NODISTANCE;
	}
	for (i = 0; i <= N; i++)
		W[i][i] = 0;
	W[1][N] = NODISTANCE;
}
void floyd(int N)
{
	int i, j, k;

	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
					D[i][j] = D[i][k] + D[k][j];
			}
		}
	}
	if (D[1][N] == NODISTANCE)
		printf("There is no solution\n");
	else
		printf("Floyd's shortest path : %d\n", D[1][N]);
}
void dijkstra(int N)
{
	int i, j, min, near;
	int* distance,* check;

	check = new int[N + 1];
	distance = new int[N + 1];

	for (i = 0; i <= N; i++) check[i] = 0;
	for (i = 1; i <= N; i++)
	{
		distance[i] = W[1][i];
	}

	for (i = 2; i <= N; i++)
	{
		min = NODISTANCE;
		for (j = 2; j <= N; j++)
		{
			if (check[j])
				continue;

			if (distance[j] < min) {
				min = distance[j];
				near = j;
			}
		}
		
		check[near] = 1;
		for (j = 2; j <= N; j++)
		{
			if (distance[near] + W[near][j] < distance[j])
				distance[j] = distance[near] + W[near][j];
		}
	}
	
	if (distance[N] == NODISTANCE)
		printf("There is no solution\n");
	else
		printf("Dijkstra's shortes path : %d\n", distance[N]);
}
int main()
{
	int N, i, j;
	double density;
	clock_t start, end;

	printf("노드 수 입력 : ");
	scanf("%d", &N);

	printf("density 입력 (0 <= density <= 100)\% : ");
	scanf("%lf", &density);
	density /= 100;
	printf("\n");

	makegraph(N);
	randgenerate(N, density);

	copy(N, &W, &D);

	printArr(N);

	start = clock();
	floyd(N);
	end = clock();
	printf("%.3fsec\n", ((double)end - start) / CLOCKS_PER_SEC);

	start = clock();
	dijkstra(N);
	end = clock();
	printf("%.3fsec\n", ((double)end - start) / CLOCKS_PER_SEC);

	return 0;
}