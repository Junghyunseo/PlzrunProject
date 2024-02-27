#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[1000005];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';
	return 0;
}