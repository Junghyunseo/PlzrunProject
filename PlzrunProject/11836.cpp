#include <iostream>

using namespace std;

int arr[1000]{};
void yose(int n, int k)
{
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
	int printCount = 0;
	int i = 0;
	int cnt = 0;

	cout << '<';
	while (1)
	{
		cnt++;
		if (cnt % k == 0)
		{
			if (arr[i])
			{
				if (printCount < n - 1)
					cout << arr[i] << ", ";
				else
					cout << arr[i] << '>';
				printCount++;
				if (printCount == n)
					break;
				arr[i] = 0;
				if (i == n - 1)
					i = 0;
				else
					i++;
			}
			else
			{
				cnt--;
				if (i == n - 1)
					i = 0;
				else
					i++;
			}
		}
		else
		{
			if (arr[i])
			{
				if (i == n - 1)
					i = 0;
				else
					i++;
			}
			else
			{
				cnt--;
				if (i == n - 1)
					i = 0;
				else
					i++;
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, K;

	cin >> N >> K;

	yose(N, K);

	return 0;
}