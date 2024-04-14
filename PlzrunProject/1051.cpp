#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	string s;
	int arr[50][50]{};

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
			arr[i][j] = s[j] - '0';
	}

	int tmp;
	if (N > M)
		tmp = M - 1;
	else
		tmp = N - 1;

	int a = 0, b = 0;

	int max = 0;

	for (int k = tmp; k > 0; k--) // 가장 큰 정사각형부터 체크
	{
		for (int i = 0; i + k < N; i++)
		{
			for (int j = 0; j + k < M; j++)
			{
				if (arr[i][j] == arr[i][j + k] && arr[i][j] == arr[i + k][j] && arr[i][j] == arr[i + k][j + k])
					if (max < k)
						max = k;
			}
		}
	}
	cout << (max + 1) * (max + 1);

	return 0;
}