#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int sang[500001];
queue<int>q;
int n, m;

void binary(int num)
{
	int st, mid, en;
	st = 0;
	en = n - 1;
	mid = (st + en) / 2;
	int cnt = 0;

	while (st <= en)
	{
		mid = (st + en) / 2;
		//cout << "mid: " << mid << '\n';

		if (num < sang[mid])
			en = mid - 1;
		else if(num > sang[mid])
			st = mid + 1;
		else
		{
			cnt = 1;
			break;
		}
	}

	cout << cnt << ' ';
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> sang[i];

	sort(sang, sang + n); // 상근이 카드 sort

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		q.push(tmp); // 일단 처음엔 없음 표시로 넣기
	}

	for (int i = 0; i < m; i++)
	{
		binary(q.front());
		q.pop();
	}

	return 0;
}