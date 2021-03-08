#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, bool> map1;
vector<string> vec;
int main()
{
	int N, M, i;
	string str;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		cin >> str;
		map1[str] = true;
	}
	for (i = 0; i < M; i++) {
		cin >> str;
		if (map1[str]==true) {
			vec.push_back(str);
		}
	}
	sort(vec.begin(), vec.end());
	printf("%d\n", vec.size());
	for (i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}
	return 0;
}