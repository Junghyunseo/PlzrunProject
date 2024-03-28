#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;

	cin >> N >> M;

	if (N == 1)
		cout << 1;
	else if (N == 2)
	{
		if (M < 3)
			cout << 1;
		else if (M == 3 || M == 4)
			cout << 2;
		else if (M == 5 || M == 6)
			cout << 3;
		else
			cout << 4;
	}
	else
	{
		if (M == 1)
			cout << 1;
		else if (M == 2)
			cout << 2;
		else if (M == 3)
			cout << 3;
		else if (M == 4 || M == 5 || M == 6)
			cout << 4;
		else
			cout << M - 2;
	}

	return 0;
}