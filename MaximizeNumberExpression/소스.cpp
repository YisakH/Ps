#include <string>
#include <vector>

using namespace std;

// 1 == +, 2 == -, 4 == *


long long cal(string expression, vector<long long> vec, vector<int> sit, int key) {
    for (int i = 0; i < 3; i++) {
        if ((key >> i) | 1 != 1) {
            continue;
        }
        switch(i)
            case 0:
                for(int j=0; j<expression.size(); )


    }
}

long long solution(string expression) {
    
    int key = 0;

    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+')
            key |= 1;
        else if (expression[i] == '-')
            key |= 2;
        else if (expression[i] == '*')
            key |= 4;
    }
    
    long long answer = 0;
    vector<long long> vec;
    vector<int> sit;

    char* tmp;
    int i = 0;

    vec.push_back(stoi(strtok((char*)expression.c_str(), "+-*")));
    sit.push_back(i++);
    while ((tmp = strtok(NULL, "+-*")) != NULL)
    {
        vec.push_back(stoi(tmp));
        sit.push_back(i++);

    }
    int j = 0;

    while (expression.find("+"))

    return answer;
}