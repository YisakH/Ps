#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N;
	map<int, int> myMap;

	scanf("%d", &N);
	vector<int> inp(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &inp[i]);

	vector<int> vec;
	vec.push_back(inp[0]); // 맨 처음 값 push
	myMap[inp[0]] = -2100000000;

	for (int i = 1; i < N; i++) {
		vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), inp[i]);
		int lower_index = iter - vec.begin();

		if (lower_index < vec.size()) {					 // lower 바운드를 찾았다면 => 값 수정
			if (myMap.find(inp[i]) != myMap.end()) continue; // 이전에 저장된 값이 있다면

			if (iter != vec.begin())
				myMap[inp[i]] = vec[lower_index - 1]; // 값이 수정될 경우 이전 인덱스 값 기억
			else
				myMap[inp[i]] = -2100000000;
			vec[lower_index] = inp[i];
		}
		else {											// lower 바운드 찾지 못했다면 => push_back()
			myMap[inp[i]] = vec[vec.size() - 1];	// 값이 수정될 경우 이전 인덱스 값 기억
			vec.push_back(inp[i]);
		}
	}

	printf("%d\n", vec.size());

	// 맵에서 값을 찾아 출력
	stack<int> st;
	int key = vec[vec.size() - 1];
	map<int, int>::iterator  iter;
	while (  (iter = myMap.find(key)) != myMap.end()) {
		st.push(key);
		key = iter->second;
	}
	//st.push(key);

	while (!st.empty()) {
		printf("%d ", st.top());
		st.pop();
	}
	//printf("\n");
	return 0;
}
