#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
set<int> myset;
set<int> twenty = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
int main()
{
	char str[10];
	int x, i, M;

	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%s", str);
		if (strcmp(str, "empty") != 0 && strcmp(str, "all") != 0)
			scanf("%d", &x);

		if (str[0] == 'a' && str[1] == 'd') {
			myset.insert(x);
		}
		else if (str[0] == 'r')
			myset.erase(x);
		else if (str[0] == 'c') {
			if (myset.find(x) != myset.end())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (str[0] == 't') {
			if (myset.find(x) != myset.end())
				myset.erase(x);
			else
				myset.insert(x);
		}
		else if (str[0] == 'a') {
			myset = twenty;
		}
		else
			myset.clear();
	}

}