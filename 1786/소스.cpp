#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPi(string T)
{
	vector<int> pi(T.length(), 0);
	int pre = 0;

	for (int i = 1; i < T.length(); i++)
	{
		while (pre > 0 && T[i] != T[pre])
			pre = pi[pre - 1];
		if (T[i] == T[pre])
			pi[i] = ++pre;
	}
	return pi;
}
int main()
{
	string P, T;
	getline(cin, P);
	getline(cin, T);
	vector<int> pi = getPi(T), ans;

	int i, j, Plen = P.length(), Tlen = T.length();
	i = j = 0;
	while (i <= Plen)
	{
		if (j == Tlen) {
			ans.push_back(i - j + 1);
			j = pi[j - 1];
		}
		else if (P[i] == T[j]) {
			j++;
			i++;
		}
		else if (j > 0) {
			j = pi[j - 1];
		}
		else
			i++;
	}
	printf("%d\n", ans.size());
	for (i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
}