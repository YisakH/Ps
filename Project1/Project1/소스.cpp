#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> visit(1000001, true);
	int m, n;
	cin >> m >> n;
	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
			visit[i] = false;
		}
	}
	visit[1] = false;
	visit[2] = true;
	visit[3] = true;
	visit[5] = true;
	visit[7] = true;

	for (int i = m; i <= n; i++) {
		if (visit[i] == true) {
			cout << i << endl;
		}
	}

	return 0;
}