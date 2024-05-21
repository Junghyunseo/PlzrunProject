#include<iostream>
#define INF 1e9

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	int arr[1001][1001];
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			arr[i][j] = INF;
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) // �Ÿ��� �� ����
	{
		int x, y, d;
		cin >> x >> y >> d;
		arr[x][y] = d;
		arr[y][x] = d;
	}

	for (int i = 1; i < N + 1; i++) // i�� ���İ��� ��츦 ���ʴ�� ������Ʈ
		for (int j = 1; j < N + 1; j++)
			for (int k = 1; k < N + 1; k++)
				if ((i != j) && (i != k)) // ���� ���İ��� �� ����
					if (arr[j][k] > arr[j][i] + arr[i][k]) // relax
						arr[j][k] = arr[j][i] + arr[i][k];

	for (int i = 0; i < M; i++) 
	{
		int x, y;
		cin >> x >> y;
		cout << arr[x][y] << '\n';
	}
	return 0;
}