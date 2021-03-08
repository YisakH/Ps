#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string str;

	cin >> str;
	int i = 0, cnt = 0;
	while (i < str.size())
	{
		if (str[i] == 'c' && (str[i + 1] == '=' || str[i+1] == '-')) {
			cnt++;
			i += 2;
		}
		else if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=') {
			cnt++;
			i += 3;
		}
		else if (str[i] == 'd' && str[i + 1] == '-') {
			cnt++;
			i += 2;
		}
		else if (str[i] == 'l' && str[i + 1] == 'j') {
			cnt++;
			i += 2;
		}
		else if (str[i] == 'n' && str[i + 1] == 'j') {
			cnt++;
			i += 2;
		}
		else if (str[i] == 's' && str[i + 1] == '=') {
			cnt++;
			i += 2;
		}
		else if (str[i] == 'z' && str[i + 1] == '=') {
			cnt++;
			i += 2;
		}
		else {
			cnt++;
			i++;
		}
	}
	printf("%d\n", cnt);
}