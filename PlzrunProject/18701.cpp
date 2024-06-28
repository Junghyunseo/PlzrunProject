#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int a = 0, b = 0, c = 0;
	for (int i = 1; i < N + 1; i++)
		a += i;
	b = a * a;
	for (int i = 1; i < N + 1; i++)
		c += i * i * i;
	cout << a << '\n' << b << '\n' << c;
	return 0;
}