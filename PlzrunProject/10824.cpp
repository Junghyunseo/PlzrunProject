#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long a, b, c, d;

	cin >> a >> b >> c >> d;

	int num1 = 1, num2 = 1;

	for (; ; num1 *= 10)
	{
		if (!(b / num1))
			break;
	}
	for (; ; num2 *= 10)
	{
		if (!(d / num2))
			break;
	}
	cout << num1 * a + b + num2 * c + d;
	return 0;
}