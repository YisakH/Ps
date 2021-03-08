#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct namelist {
	int age;
	char name[101];
}Name;

int compare(Name a, Name b) {
	return a.age < b.age;
}

int main()
{
	int N, n, i;

	scanf("%d", &N);

	Name* arr = new Name[N];

	for (n = 0; n < N; n++)
		scanf("%d %s", &arr[n].age, arr[n].name);

	stable_sort(arr, &arr[N], compare);

	for (i = 0; i < N; i++)
		printf("%d %s\n", arr[i].age, arr[i].name);
}