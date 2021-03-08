#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	map<string, int> data;
	vector<string> numdata;
	string input;
	int M, N, i, j, num;

	cin >> N >> M;

	numdata.assign(N + 1, "");
	for (i = 1; i <= N; i++) {
		cin >> input;
		data[input] = i;
		numdata[i] = input;
	}
	for (j = 1; j <= M; j++) {
		cin >> input;
		if ((num = atoi(input.c_str())) > 0)
			cout << numdata[num] << endl;
		else
			cout << data[input] << endl;

	}
}