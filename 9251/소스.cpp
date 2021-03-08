#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxlen[1001];
vector<vector<int>> strtoval(26, vector<int>{});

int main()
{
	string a, b;
	int i, max;
	cin >> a >> b;
	for (i = 0; i < b.length(); i++) {
		strtoval[b[i] - 'A'].push_back(i);
	}

	for (i = 0; i < a.length(); i++) {
		char ch = a[i];
		for (int j = strtoval[ch - 'A'].size() - 1; j >= 0; j--) {
			int max=0, key = strtoval[ch - 'A'][j];
			for (int k = 0; k < key; k++)
				if (maxlen[k] > max)
					max = maxlen[k];
			maxlen[key] = max + 1;
		}
	}
	max = 0;
	for (i = 0; i < 1001; i++)
		if (maxlen[i] > max)
			max = maxlen[i];
	printf("%d\n", max);

}