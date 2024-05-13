#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int arr[1000]{};
	int moving[1000]{};
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		arr[i] = i + 1; // 숫자 채우기
		cin >> moving[i];
	}

	int cnt = 0;
	int i = 0;

	while (cnt < N)
	{
		cout << i + 1 << ' ';
		arr[i] = 0; // 출력한 것은 0으로 만들기
		cnt++;
		if (cnt == N)
			break;
		int movingCount = moving[i];
		if (movingCount > 0) // 오른쪽으로 이동
		{
			for (int j = 0; j < movingCount; ) // 이동해야 하는 것만큼
			{
				if (i + 1 == 1000) // 오른쪽 끝이면 맨 앞으로 이동
					i = 0;
				if (arr[i + 1] != 0) // 오른쪽 칸이 0이 아니면 오른쪽으로 이동
				{
					i += 1;
					j++; // 이때만 숫자만큼 이동한 것으로 친다.
				}
				else
					i += 1;
			}
		}
		else // 왼쪽으로 이동 // movingCount가 음수일 때
		{
			int plusMovingCount = -1 * movingCount;
			for (int j = 0; j < plusMovingCount; )
			{
				if (i - 1 < 0) // 왼쪽 끝이면 맨 뒤로 이동
				{
					i = 999;
					if (arr[999] != 0)
						j++;
				}
				else
				{
					if (arr[i - 1] != 0)
					{
						i -= 1;
						j++;
					}
					else
						i -= 1;
				}
			}
		}
	}
	return 0;
}