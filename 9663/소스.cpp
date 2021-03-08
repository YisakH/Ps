#include <cstdio>
#define ABS(x) ((x>=0)? (x) : (-1 * (x)))
int pos[16];
bool checked[16];
int N;

bool find(int point, int num) // point 자리에 num이 들어갈 수 있냐
{
	int num1, num2;
	for (int i = 0; i < point; i++)
		if ((num1 = ABS(i - point)) == (num2 = ABS(num - pos[i])))
			return false;
	return true;
}

long long queens(int N, int cur)
{
	if (cur == N)
		return 1;
	long long count = 0;
	for (int j = 0; j < N; j++) {
		if (checked[j] == false && find(cur, j)) {
			pos[cur] = j;
			checked[j] = true;
			count += queens(N, cur + 1);
			checked[j] = false;
		}
	}
	return count;
}

int main()
{
	int i, j;

	for (i = 0; i < 16; i++) {
		checked[i] = false;
	}

	scanf("%d", &N);
	printf("%lld\n", queens(N, 0));
}
