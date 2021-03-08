#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <map>
#include <time.h>
#include <algorithm>

using namespace std;
string add(string ia, string ib);

map<int, string> hmap4;
map<int, string> hmap;

string hanoi(int n)
{
	int i;
	string tmp;
	for (i = n; hmap[i].length() == 0; i--);
	for (; i < n; i++)
	{
		tmp = add(hmap[i], hmap[i]);
		tmp = add(tmp, "1");
		hmap[i + 1] = tmp;
	}
	return hmap[n];
}
int mycomp(string a, string b)
{
	if (a.length() < b.length()) {
		return -1;
	}
	else if (a.length() > b.length()) {
		return 1;
	}

	return a.compare(b);
}
string add(string ia, string ib)
{
	string c, a, b;
	int i, o, alen;
	if (ia.length() <= ib.length()) {
		a = ia;
		b = ib;
	}
	else {
		b = ia;
		a = ib;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	c.resize(b.length());
	alen = a.length();
	o = 0;
	for (i = 0; i < alen; i++)
	{
		c[i] = o + a[i] + b[i] - '0';
		o = 0;
		if (c[i] > '9') {
			c[i] -= 10;
			o = 1;
		}
	}
	while (i < b.length()) {
		c[i] = b[i] + o;
		o = 0;
		if (c[i] > '9') {
			c[i] -= 10;
			o = 1;
		}
		i++;
	}
	if (o == 1) {
		c.resize(c.length() + 1);
		c[i] = '1';
		o = 0;
	}
	reverse(c.begin(), c.end());
	return c;
}
string hanoi4(int n)
{
	int k, i;
	string min, tmp;
	if (hmap4[n].length() > 0)
		return hmap4[n];

	for (i = n; hmap4[i].length() == 0; i--);
	i++;
	for (; i <= n; i++) {
		for (k = i; k >0 ; k--) {
			tmp = hanoi(i - k);
			tmp = add(tmp, hmap4[k]);
			tmp = add(tmp, hmap4[k]);

			if (k == i)
				min = tmp;
			else if (mycomp(min, tmp) > 0)
				min = tmp;
			else
				break;
		}
		hmap4[i] = min;
	}
	return hmap4[n];
}

int main() {
	string count = "0";
	int n;
	char tmp[10];
	hmap4[0] = "0";
	hmap4[1] = "1";
	hmap[1] = "1";
	hmap[0] = "0";

	while (fgets(tmp, 10, stdin))
	{
		n = atoi(tmp);
		cout << hanoi4(n) << endl;
	}

}