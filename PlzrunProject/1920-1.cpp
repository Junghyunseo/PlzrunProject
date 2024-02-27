#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long n, m;

	long long arr[100001]{};

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		arr[num] = 1;
	}

	cin >> m;


	for (int i = 0; i < m; i++)
	{
		long long num;
		cin >> num;
		cout << arr[num] << '\n';
	}

	return 0;
}