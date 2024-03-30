#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int a, b;

	cin >> a >> b;

	int arr[400000]{};

	for (int i = 0; i < a + b; i++)
		cin >> arr[i];

	sort(arr, arr + a + b);
	int cnt = 0;
	for (int i = 0; i < a + b - 1; i++)
		if (arr[i] == arr[i + 1])
			cnt++;
	cout << a + b - 2 * cnt;
	return 0;
}