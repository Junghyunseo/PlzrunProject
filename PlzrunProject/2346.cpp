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
		arr[i] = i + 1; // ���� ä���
		cin >> moving[i];
	}

	int cnt = 0;
	int i = 0;

	while (cnt < N)
	{
		cout << i + 1 << ' ';
		arr[i] = 0; // ����� ���� 0���� �����
		cnt++;
		if (cnt == N)
			break;
		int movingCount = moving[i];
		if (movingCount > 0) // ���������� �̵�
		{
			for (int j = 0; j < movingCount; ) // �̵��ؾ� �ϴ� �͸�ŭ
			{
				if (i + 1 == 1000) // ������ ���̸� �� ������ �̵�
					i = 0;
				if (arr[i + 1] != 0) // ������ ĭ�� 0�� �ƴϸ� ���������� �̵�
				{
					i += 1;
					j++; // �̶��� ���ڸ�ŭ �̵��� ������ ģ��.
				}
				else
					i += 1;
			}
		}
		else // �������� �̵� // movingCount�� ������ ��
		{
			int plusMovingCount = -1 * movingCount;
			for (int j = 0; j < plusMovingCount; )
			{
				if (i - 1 < 0) // ���� ���̸� �� �ڷ� �̵�
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