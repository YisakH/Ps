#include <cstdio>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	deque<int> deq;
	string str;
	int inp;

	scanf("%d", &inp);

	while (inp--) {
		int N;
		cin >> str;
		
		if (str.compare("push_front") == 0) {
			scanf("%d", &N);
			deq.push_front(N);
		}
		else if (str.compare("push_back") == 0) {
			scanf("%d", &N);
			deq.push_back(N);
		}
		else if (str.compare("pop_front") == 0) {
			if (deq.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deq.front());
				deq.pop_front();
			}
		}
		else if (str.compare("pop_back") == 0) {
			if (deq.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deq.back());
				deq.pop_back();
			}
		}
		else if (str.compare("size") == 0) {
			printf("%d\n", deq.size());
		}
		else if (str.compare("empty")==0) {
			printf("%d\n", deq.empty());
		}
		else if (str.compare("front")==0) {
			if (deq.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deq.front());
			}
		}
		else {
			if (deq.empty()) {
				printf("-1\n");
			}
			else {
				printf("%d\n", deq.back());
			}
		}

	}

	
}