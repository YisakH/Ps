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
	vec.push_back(inp[0]); // �� ó�� �� push
	myMap[inp[0]] = -2100000000;

	for (int i = 1; i < N; i++) {
		vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), inp[i]);
		int lower_index = iter - vec.begin();

		if (lower_index < vec.size()) {					 // lower �ٿ�带 ã�Ҵٸ� => �� ����
			if (myMap.find(inp[i]) != myMap.end()) continue; // ������ ����� ���� �ִٸ�

			if (iter != vec.begin())
				myMap[inp[i]] = vec[lower_index - 1]; // ���� ������ ��� ���� �ε��� �� ���
			else
				myMap[inp[i]] = -2100000000;
			vec[lower_index] = inp[i];
		}
		else {											// lower �ٿ�� ã�� ���ߴٸ� => push_back()
			myMap[inp[i]] = vec[vec.size() - 1];	// ���� ������ ��� ���� �ε��� �� ���
			vec.push_back(inp[i]);
		}
	}

	printf("%d\n", vec.size());

	// �ʿ��� ���� ã�� ���
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
