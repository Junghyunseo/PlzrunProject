#include<iostream>
#define INF 1e9
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	int arr[5001][5001]{};
	for (int i = 0; i < 5001; i++)
		for (int j = 0; j < 5001; j++)
			if (i != j)
				arr[i][j] = INF;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int k = 1; k < N + 1; k++)
	{
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (i != k && k != j)
					if (arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int sum = INF;
	int ansIdx = 0;
	for (int i = 1; i < N + 1; i++)
	{
		int tmpSum = 0;
		for (int j = 1; j < N + 1; j++)
			tmpSum += arr[i][j];
		if (sum > tmpSum)
		{
			sum = tmpSum;
			ansIdx = i;
		}
	}
	cout << ansIdx;
	return  0;
}