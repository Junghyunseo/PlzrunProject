#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int arr[50]{};
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int cnt = 0;
	int sum = 0;

	for (int i = 0; i < N;)
	{
		if (sum + arr[i] <= M)
			sum += arr[i++];
		else
		{
			cnt++;
			sum = 0;
		}
	}
	if (N)
		cout << cnt + 1;
	else
		cout << cnt;
	return 0;
}