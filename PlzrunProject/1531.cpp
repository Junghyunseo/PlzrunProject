#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	int arr[101][101]{};
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		for (int j = ax; j < bx + 1; j++)
			for (int k = ay; k < by + 1; k++)
				arr[j][k]++;
	}
	int cnt = 0;
	for (int i = 1; i < 101; i++)
		for (int j = 1; j < 101; j++)
			if (arr[i][j] > M)
				cnt++;
	cout << cnt;
	return 0;
}