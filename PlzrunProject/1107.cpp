#include<iostream>
#include<math.h>
#include<stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	stack<int> s;
	int present = 100;
	bool isCrash[10]{}; // ���峭 ��: true
	int N, M;
	int onlyButton = 0;
	int ans = 0;
	int digit = 100000;
	int digitdigit = 6;

	cin >> N >> M;

	if (N != 0)
	{
		while (1) // N�� �ڸ��� ���
		{
			if (N / digit > 0)
				break;
			else
			{
				digit /= 10;
				digitdigit--;
			}
		}
	}
	else
	{
		digit = 1;
		digitdigit = 1;
	}

	for (int i = 0; i < M; i++)
	{
		int tmp;
		cin >> tmp;
		isCrash[tmp] = true; // ���� ǥ��
	}

	onlyButton = abs(N - 100); // +�� - ��ư���� ������ ���� �� ���� ���ϱ�

	ans += digitdigit; // �ϴ� �ڸ�����ŭ ������
	
	int big = N; // tmp�� �־��� ���� �Ȱ��� �����, ���� 1�� ���ϴ� ��, ���� �͵� �غ���
	int small = N;

	int tmpAns = 0;

	if (M < 10)
	{
		for (int i = 0; ; i++)
		{
			int tmpBig = big + i;
			int tmpSmall = small;
			if (tmpSmall - i > 0)
				tmpSmall -= i;
			else
				tmpSmall = 0;

			int cnt = 0;
			int tmpDigit = digit;

			for (int j = 0; j < digitdigit; j++) // ��� �ڸ� ��
			{
				if (isCrash[tmpBig / tmpDigit]) // �ڸ��� �߿��� ���峭 ���� ������
					break;
				else
				{
					cnt++;
					tmpBig %= tmpDigit;
					tmpDigit /= 10;
				}
			}
			if (cnt == digitdigit)
			{
				tmpAns = i;
				s.push(tmpAns);
				//break;
			}
			cnt = 0;
			tmpDigit = digit;

			for (int j = 0; j < digitdigit; j++) // ��� �ڸ� ��
			{
				if (isCrash[tmpSmall / tmpDigit]) // �ڸ��� �߿��� ���峭 ���� ������
					break;
				else
				{
					cnt++;
					tmpSmall %= tmpDigit;
					tmpDigit /= 10;
				}
			}
			if (cnt == digitdigit)
			{
				tmpAns = i;
				s.push(tmpAns);
				//break;
			}
			if (big + i > 1000000 && small == 0) // ���� ���Ǹ� ã���� ��
				break;
		}

	}

	int min = 1e9;
	while (!s.empty())
	{
		if (min > s.top())
			min = s.top();
		s.pop();
	}

	ans += min;

	if (M == 10)
		cout << onlyButton;
	else
	{
		if (onlyButton > ans)
			cout << ans;
		else
			cout << onlyButton;
	}
	return 0;

}