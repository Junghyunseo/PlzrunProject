#include<iostream>

using namespace std;

char ch[2200][2200];

void blank(int a, int b, int width) // 가운데를 빈칸으로 채워주는 함수
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < width; j++)
			ch[a + i][b + j] = ' ';
}

void star(int a, int b, int n) // 별 채우는 함수
{
	if (n > 3) // 9개로 쪼개기
	{
		star(a, b, n / 3);
		star(a, b + n / 3, n / 3);
		star(a, b + n / 3 * 2, n / 3);

		star(a + n / 3, b, n / 3);
		blank(a + n / 3, b + n / 3, n / 3);
		star(a + n / 3, b + n / 3 * 2, n / 3);

		star(a + n / 3 * 2, b, n / 3);
		star(a + n / 3 * 2, b + n / 3, n / 3);
		star(a + n / 3 * 2, b + n / 3 * 2, n / 3);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 1 && j == 1)
					blank(a + i, b + j, 1);
				else
					ch[a + i][b + j] = '*';
			}
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	star(0, 0, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << ch[i][j];
		cout << '\n';
	}
	return 0;
}