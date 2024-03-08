#include <iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	int arr[300000];
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int remove = round(n * 0.15);
	double sum = 0;

	for (int i = remove; i < n - remove; i++)
		sum += arr[i];
	if (n == 0)
		cout << 0;
	else
		cout << round(sum / (n - 2 * remove));

	return 0;
}