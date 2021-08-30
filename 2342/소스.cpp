#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int cur, next;

	scanf("%d", &cur);
	int x = 0, y = 0, sum = 0;
	while (cur != 0) {
		scanf("%d", &next);

		if (x == 0) {
			x = cur;
			sum += 2;
		}
		else if (y == 0) {
			y = cur;
			sum += 2;
		}
		else if (x == cur || y == cur) {
			sum += 1;
		}
		else if (abs(x - y) == 2) { // 양 반대편에 있으면
			if (x == next) {
				y = cur;
				sum += 3;
			}
			else {
				x = cur;
				sum += 3;
			}
		}
		else {
			if (x == next) {
				if (abs(y - cur) == 2) {
					y = cur;
					sum += 4;
				}
				else {
					y = cur;
					sum += 3;
				}
			}
			else if (y == next) {
				if (abs(x - cur) == 2) {
					x = cur;
					sum += 4;
				}
				else {
					x = cur;
					sum += 3;
				}
			}
			else {
				if (abs(x - cur) == 2) {
					y = cur;
					sum += 3;
				}
				else {
					x = cur;
					sum += 3;
				}
			}
		}


		cur = next;
	}

	printf("%d\n", sum);
	return 0;
}