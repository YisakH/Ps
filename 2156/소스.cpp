#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct podo
{
	int no;
	int one;
	int two;
}Podo;

int mymax(int a, int b, int c)
{
	a = max(a, b);
	a = max(a, c);
	return a;
}

int input[10001];
Podo arr[2];

int main()
{
	int N;
	bool cur=false;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &input[i]);

	//arr[0].no = 0;
	//arr[0].one = arr[0].two =input[0];

	for (int i = 1; i <= N; i++)
	{
		arr[!cur].no = mymax(arr[cur].one, arr[cur].two, arr[cur].no);
		arr[!cur].one = arr[cur].no + input[i];
		arr[!cur].two = arr[cur].one + input[i];
		cur = !cur;
	}

	printf("%d\n", mymax(arr[cur].no, arr[cur].one, arr[cur].two));
}