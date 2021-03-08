#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct x {
	int val; // input ตฅภฬลอ
	int pos; // index num
	int result; // 
}X;
int compare(X x1, X x2) {
	return x1.val < x2.val;
}
int rescomp(X x1, X x2) {
	return x1.pos < x2.pos;
}

int main()
{
	int N, i;
	scanf("%d", &N);
	vector<X> vec(N, X{ 0,0 });

	for (i = 0; i < N; i++) {
		scanf("%d", &vec[i].val);
		vec[i].pos = i;
	}
	sort(vec.begin(), vec.end(), compare);
	vec[0].result = 0;
	for (i = 1; i < N; i++) {
		vec[i].result = vec[i - 1].result + 1;
		if (i > 0 && vec[i - 1].val == vec[i].val)
			vec[i].result = vec[i - 1].result;
	}

	sort(vec.begin(), vec.end(), rescomp);

	for (i = 0; i < N; i++)
		printf("%d ", vec[i].result);
}