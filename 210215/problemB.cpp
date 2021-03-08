//#include <cstdio>
//#include <vector>
//#include <cmath>
//using namespace std;
//typedef struct color
//{
//	int R;
//	int G;
//	int B;
//}Co;
//
//vector<Co> v;
//Co gom;
//bool visit[30];
//int min_val = 100000000;
//
//void solve(int N, int R, int r, int st) // N개 중 R개를 고를건데 r개를 골랐고 st부터 골라라
//{
//	static Co maked_color;
//	if (r == 0)
//		maked_color = { 0, 0, 0 };
//
//	if (r == R) {
//		int res = abs(maked_color.R/R - gom.R) + abs(maked_color.G/R - gom.G) + abs(maked_color.B/R - gom.B);
//		
//		if (res < min_val)
//			min_val = res;
//		return;
//	}
//	for (int i = st; i < N; i++) {
//		maked_color.R += v[i].R;
//		maked_color.G += v[i].G;
//		maked_color.B += v[i].B;
//
//		solve(N, R, r + 1, i + 1);
//
//		maked_color.R -= v[i].R;
//		maked_color.G -= v[i].G;
//		maked_color.B -= v[i].B;
//	}
//}
//
//int main()
//{
//	int N;
//
//	scanf("%d", &N);
//	v.assign(N, {});
//	for (int i = 0; i < N; i++) {
//		scanf("%d %d %d", &v[i].R, &v[i].G, &v[i].B);
//	}
//
//	scanf("%d %d %d", &gom.R, &gom.G, &gom.B);
//
//	for (int i = 2; i <= 7 && i <= N; i++)
//		solve(N, i, 0, 0);
//
//	printf("%d\n", min_val);
//}