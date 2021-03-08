#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int X, i, mmin;

	scanf("%d", &X);
	int* arr = new int[X+1];

	arr[0] = 0;
	arr[1] = 0;

	for (i = 2; i <= X; i++) {
		mmin = arr[i - 1]+1;
		if (i % 2 == 0)
			mmin = min(arr[i / 2] + 1, mmin);
		if (i % 3 == 0)
			mmin = min(arr[i / 3] + 1, mmin);
		arr[i] = mmin;
	}

	printf("%d\n", arr[X]);
}