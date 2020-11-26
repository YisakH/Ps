#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct elephant {
	int w;
	int iq;
};
vector<elephant> v;
int len[10000];
int before[10000];

bool compare(elephant a, elephant b)
{
	return a.w < b.w;
}

void cal()
{
	sort(v.begin(), v.end(), compare);


	return;
}

int main()
{
	int w, iq, n = 1;
	char str[30];
	elephant e;
	while (cin >> e.w >> e.iq)
		v.push_back(e);
	cal();
}