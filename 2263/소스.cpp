#include <cstdio>
#include <string>

using namespace std;
int* in, * post;

void cal(int instart, int inend, int poststart, int postend)
{
	int key = postend, inmid = 0, i;

	printf("%d ", post[key]);

	for (inmid = poststart; in[inmid] != post[key]; inmid++);

	if (instart < inmid)
		cal(instart, inmid - 1, poststart, poststart + (inmid - instart - 1));
	if (inmid  < inend)
		cal(inmid + 1, inend, poststart + (inmid - instart), postend - 1);
}

int main()
{
	int i, n;

	scanf("%d", &n);
	in = new int[n];
	post = new int[n];

	for (i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &post[i]);
	cal(0, n-1, 0, n-1);

}