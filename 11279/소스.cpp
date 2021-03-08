#include <cstdio>
#include <cstring>
class Heap
{
private:
	int heap_size;
	unsigned* arr;
public:
	Heap(int N)
	{
		heap_size = 0;
		arr = new unsigned[N + 1];
		memset(arr, 0, sizeof(arr));
	}
	void push(unsigned x) {
		unsigned tmp;
		arr[++heap_size] = x;
		int n = heap_size;
		while (n > 1 && arr[n / 2] < arr[n]) {
			tmp = arr[n / 2];
			arr[n / 2] = arr[n];
			arr[n] = tmp;
			n = n / 2;
		}
	}
	unsigned int pop()
	{
		if (heap_size == 0)
			return 0;
		int n = 1, child;
		unsigned tmp, val = arr[1];

		arr[1] = arr[heap_size];
		arr[heap_size--] = 0;
		while (n * 2 <= heap_size) {
			child = n * 2;
			if (arr[child] < arr[child + 1] && child + 1 <= heap_size)
				child++;

			if (arr[n] > arr[child])
				break;

			tmp = arr[child];
			arr[child] = arr[n];
			arr[n] = tmp;
			n = child;
		}
		return val;
	}
};

int main()
{
	int N, i;
	unsigned int x;

	scanf("%d", &N);
	Heap heap(N);

	for (i = 0; i < N; i++) {
		scanf("%u", &x);
		if (x > 0)
			heap.push(x);
		else
			printf("%u\n", heap.pop());
	}
	return 0;
}