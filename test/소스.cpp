#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int n, m, i, j, k, studenta, studentb;
	int* linepointer1;
	char answer1 = 'i';
	scanf(" %d %d", &n, &m);
	linepointer1 = (int*)malloc(n * sizeof(int));
	if (linepointer1 == NULL)
	{
		printf("메모리초과");
		exit(1);
	}
	for (i = 0; i < n; i++)
	{
		linepointer1[i] = i + 1;
	}
	for (i = 0; i < m; i++)
	{
		scanf(" %d %d", &studenta, &studentb);
		for (j = 0; j < n; j++)
		{
			if (linepointer1[j] == studenta)
			{
				answer1 = 's';
				break;
			}
			if (linepointer1[j] == studentb)
			{
				answer1 = 'c';
				for (k = j + 1; k < n; k++)
				{
					if (linepointer1[k] == studenta)
					{
						break;
					}
				}
				break;
			}
		}
		if (answer1 == 'c')
		{
			linepointer1[j] = studenta;
			linepointer1[k] = studentb;
			answer1 = 'i';
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", linepointer1[i]);
	}
	free(linepointer1);
	return 0;
}