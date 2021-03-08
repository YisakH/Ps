#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int N, i, j;
    string str;
    stack<int> s;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        cin >> str;
        if (str.compare("push") == 0) {
            cin >> j;
            s.push(j);
        }
        else {
            if (str.compare("empty") == 0) {
                if (s.empty())
                    printf("1\n");
                else
                    printf("0\n");
            }
            else if (str.compare("size") == 0) {
                printf("%d\n", s.size());
            }
            else if (str.compare("pop") == 0) {
                if (s.empty())
                    printf("-1\n");
                else {
                    printf("%d\n", s.top());
                    s.pop();
                }
            }
            else {
                if (s.empty())
                    printf("-1\n");
                else {
                    printf("%d\n", s.top());
                }
            }

        }
    }
}