#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[128][128]{};
int ansW = 0;
int ansB = 0;

void Ans(int x, int y, int N)
{
	int cnt = 0;
	int tmpComp = arr[x][y];

	for (int i = x; i < x + N; i++)
		for (int j = y; j < y + N; j++)
			if (arr[i][j] == tmpComp)
				cnt++;

	if (cnt == N * N)
	{
		if (tmpComp == 0)
			ansW++;
		else
			ansB++;
	}
	else
	{
		Ans(x, y, N / 2);
		Ans(x + N / 2, y, N / 2);
		Ans(x, y + N / 2, N / 2);
		Ans(x + N / 2, y + N / 2, N / 2);
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	Ans(0, 0, N);

	cout << ansW << '\n' << ansB;


	return 0;
}