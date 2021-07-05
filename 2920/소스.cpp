#include <cstdio>

int arr[8];

int main()
{
	for (int i = 0; i < 8; i++)
		scanf("%d", &arr[i]);

	if (arr[0] == 1) {
		for (int i = 1; i < 8; i++)
			if (arr[i] != i + 1) {
				printf("mixed\n");
				return 0;
			}
		printf("ascending");
	}
	else {
		for (int i = 0; i < 7; i++) {
			if (arr[i] != arr[i + 1] + 1) {
				printf("mixed\n");
				return 0;
			}
		}
		printf("descending\n");
	}
	return 0;
}