#include<iostream>
using namespace std;

int cache[1000][3];
int color[1000][3];
int ret = 0;
void init()
{
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 3; j++)
            cache[i][j] = -1;
    }
}
int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}
int min2(int a, int b, int c)
{
    int max = 0;
    if (a <= b && a <= c)
        max = a;
    else if (b <= a && b <= c)
        max = b;
    else if (c <= a && c <= b)
        max = c;
    return max;
}


int select(int l, int N, int t)
{
    int n, k;
    if (l == t) return color[l][N];

    if (N == 0)
    {
        n = 1;
        k = 2;
    }
    else if (N == 1)
    {
        n = 0;
        k = 2;
    }
    else if (N == 2)
    {
        n = 0;
        k = 1;
    }
    int& ret = cache[l][N];
    if (ret != -1) return ret;
    else
        return ret = min(select(l + 1, n, t), select(l + 1, k, t)) + color[l][N];
}

int main()
{
    init();
    int N;
    cin >> N;
    int a;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a;
            color[i][j] = a;
        }
    }
    int ret1, ret2, ret3;
    ret1 = select(0, 0, N);
    ret2 = select(0, 1, N);
    ret3 = select(0, 2, N);

    int result = min2(ret1, ret2, ret3);
    cout << result;
    return 0;
}