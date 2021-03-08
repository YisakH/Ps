#include <string>
#include <vector>
#include <iostream>
#define AtoB(x, y, z) (minimum[x][y] = minimum[y][x] = z)
using namespace std;

vector<vector<int>> minimum;

void floyd(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == k || minimum[i][k] < 0) continue;

            for (int j = 1; j <= n; j++) {
                if ((minimum[i][j] > minimum[i][k] + minimum[k][j] || minimum[i][j] < 0) && minimum[k][j] > 0) {
                    if (minimum[i][j] < 0 && i != j)
                        printf("%d 에서 %d를 통해 %d로 가는 길 생김\n", i, k, j);
                    minimum[i][j] = minimum[i][k] + minimum[k][j];
                }
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    minimum.assign(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < fares.size(); i++) {
        minimum[fares[i][0]][fares[i][1]] = fares[i][2];
        minimum[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for (int i = 0; i <= n; i++)
        minimum[i][i] = 0;
    floyd(n);

    int minfares = 210000000;

    for (int i = 0; i <= n; i++) {
        if (( 0 < minimum[s][i] + minimum[i][a] + minimum[i][b]) && 
            (minimum[s][i] + minimum[i][a] + minimum[i][b] < minfares))
            minfares = minimum[s][i] + minimum[i][a] + minimum[i][b];
    }

    return minfares;
}

int main()
{
    minimum.assign(5 + 1, vector<int>(6, -1));

    AtoB(1, 5, 1);
    AtoB(4, 3, 1);
    AtoB(3, 5, 1);
    AtoB(2, 4, 1);

    floyd(5);
}