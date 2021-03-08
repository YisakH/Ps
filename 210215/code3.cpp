//#include <cstdio>
//#include <vector>
//#define KEY 1000000007
//using namespace std;
//int arr[100001][8];
//vector<vector<int>> list;
//
//int solve(int N, int M, int st, int route)
//{
//	if (arr[st][route] > 0)
//		return arr[st][route];
//	else if (route == 1)
//		return list[st].size();
//
//
//	int sum = 0;
//	for (int i = 0; i < list[st].size(); i++)
//	{
//		sum = (sum + solve(N, M, list[st][i], route - 1)) % KEY;
//	}
//	arr[st][route] = sum;
//	return sum;
//}
//
//int main()
//{
//	int N, M, u, v;
//	int sum = 0;
//	scanf("%d %d", &N, &M);
//	list.assign(N + 1, {});
//	for (int i = 1; i <= M; i++) {
//		scanf("%d %d", &u, &v);
//		list[u].push_back(v);
//		list[v].push_back(u);
//	}
//	for (int i = 1; i <= N; i++)
//		sum = (sum + solve(N, M, i, 7)) % KEY;
//
//	printf("%d\n", sum);
//}
