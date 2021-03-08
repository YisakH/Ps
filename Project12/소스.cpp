#include <string>
#include <vector>

using namespace std;

int cal(vector<int>* numbers, int target, int N)
{
    if (N == 0) {
        if (target == numbers->at(0) || target == -1*numbers->at(0))
            return 1;
        else
            return 1;
    }
    int res1, res2;
    int tar1 = target - numbers->at(N), tar2 = target + numbers->at(N);

    res1 = cal(numbers, tar1, N - 1);
    res2 = cal(numbers, tar2, N - 1);
    printf("%d¿¡¼­ tar : %d, %d + %d\n", N, target, res1, res2);
    return  res1 + res2;
}

int solution(vector<int> numbers, int target) {
    int answer;
 
    answer = cal(&numbers, target, numbers.size()-1);

    return answer;
}
int main()
{
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    printf("%d\n", solution(numbers, 3));
}