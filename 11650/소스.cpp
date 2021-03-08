#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct posi {
	int x;
	int y;
}Pos;

int compare(Pos a, Pos b) {
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

int main()
{
	int N, n, i;

	scanf("%d", &N);

	Pos* arr = new Pos[N];

	for (n = 0; n < N; n++) {
		scanf("%d %d", &arr[n].x, &arr[n].y);
	}
	sort(arr, &arr[N], compare);

	for (n = 0; n < N; n++) {
		printf("%d %d\n", arr[n].x, arr[n].y);
	}
	return 0;
}