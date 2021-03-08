//#include <stdio.h>
//int result[9][9] = { 0, };
//long long cnt = 0;
//int remain;
//void initarr(int result[9][9])
//{
//	int i, j;
//	for (i = 1; i <= 8; i++)
//		for (j = 1; j <= 8; j++)
//			result[i][j] = 0;
//}
//void add(int a, int b, int n)
//{
//	int i, j;
//
//	for (i = a, j = b; i > 1 && j > 1; i--, j--);
//
//	for (; i <= n && j <= n; i++, j++)
//	{
//		result[i][j] = 1;
//	}
//
//	for (i = a, j = b; i < n && j>1; i++, j--);
//
//	for (; i >= 1 && j <= n; i--, j++)
//		result[i][j] = 1;
//}
//void copy(int src[9][9], int dest[9][9], int n)
//{
//	int i, j;
//	for (i = 1; i <= n; i++)
//		for (j = 1; j <= n; j++)
//			dest[i][j] = src[i][j];
//}
//void cal(int n, int h, int k, int a, int b)
//{
//	int i, j;
//	int savearr[9][9];
//
//	if (h == 0) {
//		cnt++;
//		return;
//	}
//	if (h == k) {
//		initarr(result);
//		remain = n * n;
//	}
//	for (i = a; i <= n ; i++)
//	{
//		j = (i == a) ? b : 1;
//		for (; j <= n ; j++)
//		{
//			if (remain < h)
//				return;
//			if (result[i][j] == 0) {
//				copy(result, savearr, n);
//				add(i, j, n);
//				remain--;
//				cal(n, h-1, k, i, j+1);
//				remain++;
//				copy(savearr, result, n);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int n, k, T, t;
//
//	while (1)
//	{
//		cnt = 0;
//		scanf("%d %d", &n, &k);
//		remain = n * n;
//		if (n == 0)
//			break;
//		initarr(result);
//		cal(n, k, k, 1, 1);
//		printf("%lli\n", cnt);
//	}
//}