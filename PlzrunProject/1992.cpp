#include<iostream>

using namespace std;
int N;
int arr[64][64]{};

void quad(int a, int b, int width)
{
	int sum = 0; // width x width 안에 시작 좌표에 해당하는 숫자와 같은 것이 몇 개 있는지
	for (int i = 0; i < width; i++)
		for (int j = 0; j < width; j++)
			if (arr[a + i][b + j] == arr[a][b]) // arr[a][b]: 시작 좌표의 숫자
				sum++;
	if (sum == width * width) // 해당 범위 내의 모든 숫자가 같을 경우 묶여서 출력
	{
		cout << arr[a][b];
	}
	else // 해당 범위 내에 다른 숫자가 있을 경우 쪼개서 검사하기
	{
		cout << '(';
		quad(a, b, width / 2);
		quad(a, b + width / 2, width / 2);
		quad(a + width / 2, b, width / 2);
		quad(a + width / 2, b + width / 2, width / 2);
		cout << ')';
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j] - '0';
	}

	quad(0, 0, N);

	return 0;
}