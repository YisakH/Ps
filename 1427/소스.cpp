#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int arr[20];
	int input, size;

	scanf("%d", &input);

	for (size = 0; input > 0; size++)
	{
		arr[size] = input % 10;
		input /= 10;
	}

	sort(arr, arr+size, greater<int>());

	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
}