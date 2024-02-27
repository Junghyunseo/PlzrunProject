#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long n, m;

	cin >> n >> m;

	long long five = 0;
	long long two = 0;

	// 5ÀÇ ÃÑ °³¼ö
	for (long long i = 1; n >= 5 * i; i *= 5)
		five += n / (5 * i);

	for (long long i = 1; n - m >= 5 * i; i *= 5)
		five -= (n - m) / (5 * i);

	for (long long i = 1; m >= 5 * i; i *= 5)
		five -= m / (5 * i);

	// 2ÀÇ ÃÑ °³¼ö
	for (long long i = 1; n >= 2 * i; i *= 2)
		two += n / (2 * i);

	for (long long i = 1; n - m >= 2 * i; i *= 2)
		two -= (n - m) / (2 * i);

	for (long long i = 1; m >= 2 * i; i *= 2)
		two -= m / (2 * i);

	if (five < two)
		cout << five;
	else
		cout << two;

	return 0;
}