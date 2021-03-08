#include <iostream>
using namespace std;
int main()
{
	int mul, a, b, q = 1;

	cin >> a >> b;
	mul = a * b;

	while (b != 0)
	{
		q = a % b;
		a = b;
		b = q;
	}
	cout << a << endl;
	cout << mul / a << endl;

}