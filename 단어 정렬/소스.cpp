#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void isIn(vector<int>& v, int i) {
	int mid, first = 0, last = v.size()-1;

	while (first <= last) {
		mid = (first + last) / 2;
		if (v[mid] == i) {
			printf("1\n");
			return;
		}
		else if (v[mid] < i)
			first = mid + 1;
		else
			last = mid - 1;
	}
	printf("0\n");
}

int main()
{
	int N, M, i, input;
	vector<int> v;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		scanf("%d",  &input);
		v.push_back(input);
	}
	sort(v.begin(), v.end());

	cin >> M;
	for (i = 0; i < M; i++) {
		scanf("%d", &input);
		isIn(v, input);
	}
}