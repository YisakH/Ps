#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int>> v;
int len[10000];
int before[10000];

void cal()
{
	int i, j, max_index;
	bool chk;
	stack<int> s;

	sort(v.begin(), v.end());

	for (i = 0; i < 10000; i++) 
		before[i] = -1;
	
	for (i = 0; i < v.size(); i++)
	{
		max_index = 0;
		chk = 0;
		for (j = 0; j <= i; j++)
		{
			if (v[j][1] > v[i][1]) {
				if (len[max_index] < len[j])
					max_index = j;
				else if (len[max_index] == len[j] && v[max_index][2] > v[j][2])
					max_index = j;
				chk = 1;
			}
		}
		len[i] = len[max_index] + 1;
		if (chk)
			before[i] = max_index;
	}
	max_index = 0;
	for (i = 1; i < v.size(); i++) {
		if (len[max_index] < len[i])
			max_index = i;
		else if (len[max_index] == len[i] && v[i][2] < v[max_index][2])
			max_index = i;
	}
	while (before[max_index] != -1) {
		s.push(v[max_index][2]);
		max_index = before[max_index];
	}
	s.push(v[max_index][2]);

	printf("%d\n", s.size());

	while (!s.empty()) {
		printf("%d\n", s.top());
		s.pop();
	}

	return;
}

int main()
{
	int w, iq, n = 1;
	char str[30];
	while (fgets(str, 29, stdin))
	{
		vector<int> tmp;
		sscanf(str, "%d %d", &w, &iq);
		tmp.push_back(w);
		tmp.push_back(iq);
		tmp.push_back(n++);
		v.push_back(tmp);
	}
	cal();
}