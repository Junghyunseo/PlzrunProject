#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	int A[100][100]{}, B[100][100]{}, C[100][100]{};
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int h = 0; h < K; h++)
		{
			int sum = 0;
			for (int j = 0; j < M; j++)
			{
				sum += A[i][j] * B[j][h];
			}
			C[i][h] = sum;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << C[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}