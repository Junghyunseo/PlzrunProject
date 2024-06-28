#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int arr[101]{};

	int a, b, c;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		for (int j = a; j <= b; j++)
			arr[j] = c;
	}
	for (int i = 1; i < N + 1; i++)
		cout << arr[i] << ' ';

	return 0;
}