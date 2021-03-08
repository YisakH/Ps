#include <set>
#include <iostream>
using namespace std;

int main()
{
	int t, T;

	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		int K, i, j, n;
		char ch;
		multiset<int> myset;

		scanf("%d", &K);
		for (i = 0; i < K; i++)
		{
			scanf(" %c %d", &ch, &n);

			if (ch == 'I')
				myset.insert(n);
			else if (ch == 'D') {
				if (myset.size() == 0)
					continue;
	
				if (n == 1)
					myset.erase(--myset.end());
				else
					myset.erase(myset.begin());
			}
		}

		if (myset.size() == 0)
			printf("EMPTY\n");
		else {
			multiset<int>:: iterator it;
			printf("%d %d\n", *(--myset.end()), *myset.begin());
		}
	}
}