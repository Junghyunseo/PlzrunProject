#include <iostream>

using namespace std;

int main(void)
{
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a = 0, b = 0, c = 0, d = 0;
		cin >> num;
		a = num / 25;
		num %= 25;
		b = num / 10;
		num %= 10;
		c = num / 5;
		num %= 5;
		d = num;
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
	return 0;
}