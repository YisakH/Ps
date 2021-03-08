#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;

vector<int> matrixes;
int** M;

int muzacmin = -1;
int dpmin = -1;

void initdata(int max_matlen)
{
	int i, j;
	M = (int**)malloc(sizeof(int*) * max_matlen + 1);
	for (i = 0; i <= max_matlen; i++)
	{
		M[i] = (int*)malloc(sizeof(int) * max_matlen + 1);
	}
	for (i = 0; i <= max_matlen; i++)
		for (j = 0; j <= max_matlen; j++)
			M[i][j] = -1;
}
void makeMat(int max_n, int max_matlen)
{
	srand((unsigned)time(NULL));
	
	for (int i = 0; i <= max_matlen; i++)
		matrixes.push_back((rand() % max_n) + 1);
}
void muzac(int max_matlen)
{
	int i, j, k, tmp;
	static vector<int> check(max_matlen+1);
	static int count = 0, depth =0;

	if (depth == max_matlen-1)
	{
		if (muzacmin == -1 || count < muzacmin)
			muzacmin = count;
		return;
	}

	for (i = 1; i < max_matlen; i++)
	{
		if (check[i]==1)
			continue;

		check[i] = 1;
		tmp = count;
		for (j = i - 1; check[j] == 1; j--);
		for (k = i + 1; check[k] == 1; k++);
		count += matrixes[j] * matrixes[i] * matrixes[k];
		depth++;

		muzac(max_matlen);

		depth--;
		check[i] = 0;
		count = tmp;
	}
}

void dp(int max_len)
{
	int dia, i, j, k;
	int min, cal;

	for (i = 0; i <= max_len; i++)
		M[i][i] = 0;

	for (dia = 1; dia < max_len; dia++)
	{
		for (i = 1; i <= max_len - dia; i++)
		{
			j = i + dia;
			min = -1;
			for (k = i; k < j ; k++)
			{
				cal = M[i][k] + M[k + 1][j] + matrixes[i-1] * matrixes[k] * matrixes[j];
				if (min == -1 || cal < min)
					min = cal;
			}
			M[i][j] = min;
		}
	}
	dpmin = M[1][max_len];
}

int main()
{
	int max_matlen;
	clock_t start, end;
	int i, j;

	printf("������ ������ ����� n�� ����ϴ�.\n");
	printf("n �Է� : ");
	scanf("%d", &max_matlen);

	initdata(max_matlen);
	makeMat(10, max_matlen);

	printf("��� ���� ��� : ");
	for (i = 0; i <= max_matlen; i++)
		printf("%d ", matrixes[i]);
	printf("\n\n");

	start = clock();
	muzac(max_matlen);
	end = clock();
	printf("������ �˰����� ����� : %d\n", muzacmin);
	printf("������ �˰����� �ɸ� �ð� : %.4fsec\n\n", (double)(end - start)/CLOCKS_PER_SEC);

	start = clock();
	dp(max_matlen);
	end = clock();
	printf("���� ��ȹ�� ����� : %d\n", dpmin);
	printf("���� ��ȹ�� �ɸ� �ð� : %.4fsec\n\n", (double)(end - start)/CLOCKS_PER_SEC);

	return 0;
}