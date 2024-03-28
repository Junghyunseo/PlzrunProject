#include<iostream>
#include<math.h>
#include<stack>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	stack<int> s;
	int present = 100;
	bool isCrash[10]{}; // 고장난 것: true
	int N, M;
	int onlyButton = 0;
	int ans = 0;
	int digit = 100000;
	int digitdigit = 6;

	cin >> N >> M;

	if (N != 0)
	{
		while (1) // N의 자릿수 계산
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
		isCrash[tmp] = true; // 고장 표시
	}

	onlyButton = abs(N - 100); // +나 - 버튼만을 눌렀을 때의 값 이후 비교하기

	ans += digitdigit; // 일단 자릿수만큼 누르기
	
	int big = N; // tmp를 주어진 수와 똑같이 만들고, 이후 1을 더하는 것, 빼는 것들 해보기
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

			for (int j = 0; j < digitdigit; j++) // 모든 자리 비교
			{
				if (isCrash[tmpBig / tmpDigit]) // 자릿수 중에서 고장난 것이 있으면
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

			for (int j = 0; j < digitdigit; j++) // 모든 자리 비교
			{
				if (isCrash[tmpSmall / tmpDigit]) // 자릿수 중에서 고장난 것이 있으면
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
			if (big + i > 1000000 && small == 0) // 종료 조건만 찾으면 됨
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