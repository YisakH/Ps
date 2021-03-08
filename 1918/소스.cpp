#include <cstdio>
#include <stack>
#include <cstdio>
using namespace std;

int main()
{
	char str[101];
	char ch;
	int i, j;

	scanf("%s", str);
	stack<char> st;
	for (i = 0; (ch = str[i]) != '\0'; i++) {
		if (ch == '+' || ch == '-') {
			while(!st.empty() && st.top() != '(') {
				printf("%c", st.top());
				st.pop();
			}
			st.push(ch);
		}
		else if (ch == '*' || ch == '/') {
			while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
				printf("%c", st.top());
				st.pop();
			}
			st.push(ch);
		}
		else if (ch == '(')
			st.push(ch);
		else if (ch == ')') {
			while (st.top() != '(') {
				printf("%c", st.top());
				st.pop();
			}
			st.pop();
		}
		else
			printf("%c", ch);
	}
	while (!st.empty()) {
		printf("%c", st.top());
		st.pop();
	}
}