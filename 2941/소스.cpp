#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> list = {
	"c=",
	"c-",
	"z=",
	"dz=",
	"d-",
	"lj",
	"nj",
	"s="
};
int main()
{
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		string slice = str.substr(i, 2);
		for (int j = 0; j < list.size(); j++) {
			if (slice.compare(list[j]) == 0) {
				cnt++;
				i++;
			}
		}
		slice = str.substr(i, 3);
		if (slice.compare(list[3]) == 0) {
			cnt++;
			i += 2;
		}
	}
	printf("%d\n", cnt);
}