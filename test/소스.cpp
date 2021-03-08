#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstring> // memset

using namespace std;

#define MAX_SIZE 100000+1

int N, K;
bool yourvisit[MAX_SIZE];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[100001];

int my()
{
	int i, tmp;
	memset(visited, sizeof(visited), false);

	pq.push({ 0, N });
	while (!pq.empty())
	{
		pair<int, int> point = pq.top();
		pq.pop();
		if (point.second == K) {
			return point.first;
		}

		if (point.second <= 50000 && !visited[point.second * 2]) {
			pq.push({ point.first, point.second * 2 });
			visited[point.second * 2] = true;
		}
		if (point.second > 1 && !visited[point.second - 1]) {
			pq.push({ point.first + 1, point.second - 1 });
			visited[point.second - 1] = true;
		}

		if (point.second <= 100000 && !visited[point.second + 1]) {
			pq.push({ point.first + 1, point.second + 1 });
			visited[point.second + 1] = true;
		}

	}
}

int bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 0, N });
    yourvisit[N] = true;
    while (!q.empty()) {
        int time = q.top().first;
        int x = q.top().second;
        q.pop();

        if (x == K) return time;

        if (x * 2 < MAX_SIZE && !yourvisit[x * 2]) {
            q.push({ time, x * 2 });
            yourvisit[x * 2] = true;
        }

        if (x + 1 < MAX_SIZE && !yourvisit[x + 1]) {
            q.push({ time + 1, x + 1 });
            yourvisit[x + 1] = true;
        }

        if (x - 1 >= 0 && !yourvisit[x - 1]) {
            q.push({ time + 1 , x - 1 });
            yourvisit[x - 1] = true;
        }
    }
}

int main() {
	while (1) {
		srand((unsigned)time(NULL));
		N = (rand() % rand()) % 100000;
		K = (rand() % rand()) % 100000;
		for (int i = 0; i < 100001; i++) {
			visited[i] = false;
			yourvisit[i] = false;
		}
		while (!pq.empty()) pq.pop();

		int your = bfs(), one = my();
		if (your != one) {
			printf("N : %d, K : %d\n", N, K);
			printf("one : %d, your :  %d\n", one, your);
		}
	}
    return 0;
}