#include <cstdio>
#include <stack>
using namespace std;
int main()
{
	int T, t, i;
	char str[51];
	bool isYes;
	stack<int> st;

	scanf("%d", &T);

	for (t = 0; t < T; t++)
	{
		scanf("%s", str);
		stack<int> st;
		isYes = true;
		for (i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(')
				st.push(1);
			else {
				if (st.empty()) {
					isYes = false;
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (isYes && st.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
}