#include <stdio.h>

int arr[][3] = { {1, 2, 3}, {4} };

int main()
{
	printf("%d\n", sizeof(arr[1]));
}