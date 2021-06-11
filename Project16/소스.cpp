#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> h_map;
    int leftindex = 0, min_left = 0, min_right = 200000;

    for (int i = 0; i < gems.size(); i++) {
        if (h_map.find(gems[i]) == h_map.end()) {
            h_map[gems[i]] = 0;
        }
    }
    int gems_size = h_map.size();
    int input_size = 0;
    h_map.clear();

    for (int i = 0; i < gems.size(); i++) {
        if (h_map.find(gems[i]) == h_map.end()) {
            input_size++;
        }

        h_map[gems[i]] = i;
        while (h_map[gems[leftindex]] != leftindex) {
            leftindex++;
        }

        if (input_size == gems_size && (min_right - min_left > i - leftindex)) {
            min_left = leftindex;
            min_right = i;
        }
    }

    vector<int> answer;
    answer.push_back(min_left+1);
    answer.push_back(min_right+1);

    return answer;
}

int main()
{
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };

    vector<int> answer;

    answer = solution(gems);

    printf("%d %d", answer[0], answer[1]);
}