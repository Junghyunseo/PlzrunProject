#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[3] = { 1,2,3 };

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		int aIdx = 0;
		int bIdx = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a == arr[j])
				aIdx = j;
			if (b == arr[j])
				bIdx = j;
		}
		int tmp = arr[aIdx];
		arr[aIdx] = arr[bIdx];
		arr[bIdx] = tmp;
	}

	cout << arr[0];

	return 0;
}