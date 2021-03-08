//#include <cstdio>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//typedef struct display
//{
//	int ppi;
//	int pos;
//}Dis;
//vector<Dis> v;
//
//int compare(Dis a, Dis b) {
//	if (a.ppi != b.ppi)
//		return a.ppi > b.ppi;
//	return a.pos <= b.pos;
//}
//int main()
//{
//	int N;
//
//	scanf("%d", &N);
//	v.assign(N, {});
//	for (int i = 0; i < N; i++) {
//		int W, H;
//		scanf("%d %d", &W, &H);
//		v[i].pos = i;
//		v[i].ppi = W * W + H * H;
//	}
//	sort(v.begin(), v.end(), compare);
//
//	for (int i = 0; i < N; i++)
//		printf("%d\n", v[i].pos + 1);
//
//	return 0;
//}