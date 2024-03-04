#include<iostream>

using namespace std;

int arr[2200][2200]{};
int minusOne = 0, zero = 0, one = 0;

void search(int sti, int stj, int width)
{
	int num = arr[sti][stj];
	int count = 0;

	for (int i = sti; i < sti + width; i++)
	{
		for (int j = stj; j < stj + width; j++)
		{
			if (arr[i][j] == num)
				count++;
			else
				break;
		}
	}

	if (count == width * width) // 3의 제곱개가 모두 같으면 
	{
		if (num == -1)
			minusOne++;
		else if (!num)
			zero++;
		else
			one++;
	}
	else // 아니면 9개로 쪼개기
	{
		if (width > 1)
		{
			search(sti, stj, width / 3); // 9개의 칸 중 1, 1
			search(sti, stj + width / 3, width / 3); // 9개의 칸 중 1, 2
			search(sti, stj + width / 3 * 2, width / 3); // 9개의 칸 중 1, 3
			
			search(sti + width / 3, stj, width / 3); // 2, 1
			search(sti + width / 3, stj + width / 3, width / 3); // 정가운데, (2, 2)
			search(sti + width / 3, stj + width / 3 * 2, width / 3); // 2, 3

			search(sti + width / 3 * 2, stj, width / 3); // 3, 1
			search(sti + width / 3 * 2, stj + width / 3, width / 3); // 3, 2 
			search(sti + width / 3 * 2, stj + width / 3 * 2, width / 3); // 3, 3
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < n + 1; j++)
			cin >> arr[i][j];

	search(1, 1, n); // 시작점 1,1과 한 변의 길이 n

	cout << minusOne << '\n' << zero << '\n' << one;
	return 0;
}