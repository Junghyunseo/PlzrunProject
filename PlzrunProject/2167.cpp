#include <iostream>

using namespace std;

int N, M;

int arr[301][301];

int sum(int i, int j, int x, int y)
{
	int sum = 0;
	for (int a = i; a < x + 1; a++)
		for (int b = j; b < y + 1; b++)
			sum += arr[a][b];

	return sum;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int k;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	cin >> k;

	for (int a = 0; a < k; a++)
	{
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << sum(i - 1, j - 1, x - 1, y - 1) << '\n';
	}

	return 0;
}