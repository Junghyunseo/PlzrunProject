#include <iostream>

using namespace std;

char arr[3072][6143];

void star(int a, int b, int n) // a, b: x, yÁÂÇ¥
{
	if (n > 3)
	{
		star(a, b, n / 2);
		star(a + n / 2, b - n / 2, n / 2);
		star(a + n / 2, b + n / 2, n / 2);
	}
	else
	{
		arr[a][b] = '*';
		arr[a + 1][b - 1] = '*';
		arr[a + 1][b + 1] = '*';
		for (int i = 0; i < 5; i++)
			arr[a + 2][b - 2 + i] = '*';
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < 3072; i++)
		for (int j = 0; j < 6143; j++)
			arr[i][j] = ' ';

	int N;
	cin >> N;

	star(0, (2 * N - 1) / 2, N / 2);
	star(N / 2, (2 * N - 1) / 2 - N / 2, N / 2);
	star(N / 2, (2 * N - 1) / 2 + N / 2, N / 2);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2 * N - 1; j++)
			cout << arr[i][j];
		cout << '\n';
	}

	return 0;
}