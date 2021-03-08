#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int x, y, w, h, min_val = 1000;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	min_val = min(x, y);
	min_val = min(min_val, min(w - x, h - y));
	printf("%d\n", min_val);
}