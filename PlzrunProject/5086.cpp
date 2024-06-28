#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int a, b;
	while (1)
	{
		cin >> a >> b;
		if (!a && !b)
			break;
		else
		{
			if (!(a % b))
				cout << "multiple" << '\n';
			else if (!(b % a))
				cout << "factor" << '\n';
			else
				cout << "neither" << '\n';
		}
	}
	return 0;
}