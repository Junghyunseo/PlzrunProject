#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int x[3]{}, y[3]{};

	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
	}
	if (x[0] == x[1])
		cout << x[2] << ' ';
	else if (x[0] == x[2])
		cout << x[1] << ' ';
	else
		cout << x[0] << ' ';
	if (y[0] == y[1])
		cout << y[2];
	else if (y[0] == y[2])
		cout << y[1];
	else
		cout << y[0];
	return 0;
}