#include<iostream>

using namespace std;

int main(void)
{
	int N, M;
	int arr[101]{};
	for (int i = 1; i < 101;i++)
		arr[i] = i;
	cin >> N >> M;

	int a, b, tmp;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	for (int i = 1; i < N + 1; i++)
		cout << arr[i] << ' ';

	return 0;
}