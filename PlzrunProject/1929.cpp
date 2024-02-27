#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int m, n;

	cin >> m >> n;

	int arr[1000001]{}; // °³²ÜÆÁ!


	for (int i = 2; i < 1001; i++)
		if (!arr[i])
			for (int j = 2; i * j < 1000001; j++)
				arr[i * j] = 1;
	arr[1] = 1;

	for (int i = m; i < n + 1; i++)
	{
		if (!arr[i])
			cout << i << '\n';
	}
	return 0;
}