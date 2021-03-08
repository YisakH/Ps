
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> solution(int n, vector<int> t1, vector<int> t2);

int main()
{
    vector<int> result;
    vector<vector <int>> seat = { {1, 2} };

    solution(seat);
    result;
}

int solution(vector<vector<int>> seat) {
    int answer = 0;
    int i;
    bool** arr;
    arr = (bool**)malloc(sizeof(bool) * 100002);
    for (i = 0; i < 10002; i++)
        arr[i] = (bool*)malloc(sizeof(bool) * 100002);

    for (i = 0; i < seat.size(); i++)
    {
        if (arr[seat[i][0]][seat[i][1]] == 0) {
            answer++;
            arr[seat[i][0]][seat[i][1]] = 1;
        }
    }

    return answer;
}