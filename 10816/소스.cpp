#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int lower(int *arr, int start, int end, int key)
{
	int mid = (end - start) / 2;
	int i;

	while (start <= end) {
		if (mid < key) {
			start = mid + 1;
		}
		else if (mid >= key) {
			end = mid; 
		}
	}
	cout << mid;
	return 1;
}

int main()
{
	int N, M, n, m, i, inp;
	int* arr;

	scanf("%d", &N);

	arr = new int [N];

	for (n = 0; n < N; n++) {
		scanf("%d", &inp);
		arr[n] = inp;
	}

	sort(arr, &arr[N]);
	scanf("%d", &M);

	for (m = 0; m < M; m++) {
		scanf("%d", &inp);
		printf("%d ", upper_bound(arr, &arr[N], inp) - lower_bound(arr, &arr[N], inp));
	}
}