#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int N, i, j, sum1 = 0, sum2 = 0, sum3 = 0, n1, n2, n3, t1, t2, t3;

    scanf("%d", &N);

    scanf("%d %d %d", &sum1, &sum2, &sum3);

    for (i = 1; i < N; i++) {
        scanf("%d %d %d", &n1, &n2, &n3);

        t1 = min(sum2, sum3) + n1;
        t2 = min(sum1, sum3) + n2;
        t3 = min(sum1, sum2) + n3;

        sum1 = t1;
        sum2 = t2;
        sum3 = t3;
    }

    int result = min(sum1, sum2);
    result = min(result, sum3);
    printf("%d\n", result);

    return 0;
}