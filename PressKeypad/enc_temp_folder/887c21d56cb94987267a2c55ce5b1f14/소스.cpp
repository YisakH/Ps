#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;



string solution(vector<int> numbers, string hand) {
    string answer = "";
    int i, leftx, lefty, rightx, righty;

    leftx = 0, lefty = 3;
    rightx = 2, righty = 3;

    for (i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 1) {
            answer += "L";
            lefty = numbers[i] / 3;
        }
        else if (numbers[i] != 0 && numbers[i] % 3 == 0) {
            answer += "R";
            righty = numbers[i] / 3 - 1;
        }
        else {
            int midy = (numbers[i] == 0) ? 3 : numbers[i] / 3;
            int distantleft = abs(midy - lefty) + abs(1 - leftx);
            int distantright = abs(midy - righty) + abs(1 - rightx);

            if ((distantleft > distantright) || (hand == "right" && (distantleft == distantright))) {
                answer += "R";
                rightx = 1;
                righty = midy;
            }
            else {
                answer += "L";
                leftx = 1;
                lefty = midy;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> vec = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string str;

    cout << solution(vec, "right");
}