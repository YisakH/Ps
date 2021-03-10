#include <cstdio>

int arr[11], op[4];
int N, min=1100000000, max = -1100000000;

void cal(int result, int pos)
{
	if (pos == N) {
		if (result < min)
			min = result;
		if (result > max)
			max = result;
		return;
	}

	if (op[0] > 0) {
		result += arr[pos];
		op[0]--;
		cal(result, pos + 1);
		result -= arr[pos];
		op[0]++;
	}
	if (op[1] > 0) {
		result -= arr[pos];
		op[1]--;
		cal(result, pos + 1);
		result += arr[pos];
		op[1]++;
	}
	if (op[2] > 0) {
		result *= arr[pos];
		op[2]--;
		cal(result, pos + 1);
		result /= arr[pos];
		op[2]++;
	}
	if (op[3] > 0) {
		result /= arr[pos];
		op[3]--;
		cal(result, pos + 1);
		result *= arr[pos];
		op[3]++;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 4; i++)
		scanf("%d", &op[i]);

	cal(arr[0], 1);

	printf("%d\n", max);
	printf("%d\n", min);
}