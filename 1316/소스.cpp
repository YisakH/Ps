#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, cnt=0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int arr[30];
		char before;
		string str;
		bool isGroup = true;

		for (int j = 0; j < 30; j++)
			arr[j] = 0;

		cin >> str;
		before = str[0];
		arr[before - 'a'] = 1;

		for (int j = 0; j < str.size(); j++) {
			char ch = str[j];
			if (before != ch && arr[ch-'a'] == 1) {
				isGroup = false;
				break;
			}
			else if (before != ch) {
				arr[ch - 'a'] = 1;
			}
			before = ch;
		}

		if (isGroup)
			cnt++;
	}
	printf("%d\n", cnt);
}