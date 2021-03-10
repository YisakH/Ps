#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	double area1, area2, pi = M_PI;
	int n;

	scanf("%d", &n);

	area1 = n * n * pi;
	area2 = 2 * n * n;

	printf("%lf\n", area1);
	printf("%lf\n", area2);
}