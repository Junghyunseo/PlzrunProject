#include<iostream>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;

int n, m;
int sang[500001];
queue<int> q;
map<int, int> mapp;

void binary(int num)
{
	int cnt = 0;
	int st = 0;
	int en = n - 1;
	int mid;

	while (st <= en)
	{
		mid = (st + en) / 2;
		if (num >= sang[mid])
		{
			if (num == sang[mid])
			{
				cnt++;
				break;
			}
			st = mid + 1;
		}
		else if (num < sang[mid])
			en = mid - 1;
		/*if (num == sang[mid]) // 처음 풀이 -> 시간 초과
		{
			cnt++;
			for (int i = mid + 1; ; i++)
			{
				if (num == sang[i])
					cnt++;
				else
					break;
			}
			for (int i = mid - 1; ; i--)
			{
				if (num == sang[i])
					cnt++;
				else
					break;
			}
			break;
		}*/
	}
	if (cnt)
		cout << mapp[sang[mid]] << ' ';
	else
		cout << 0 << ' ';
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> sang[i];
	sort(sang, sang + n);
	/*for (int i = 0; i < n; i++)
		cout << sang[i] << ' ';
	cout << '\n';*/

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	mapp.insert({ sang[0],1 });

	for (int i = 1; i < n; i++)
	{
		if (sang[i] != sang[i - 1]) // 앞서 나온 숫자가 아니면 새로 저장
			mapp.insert({ sang[i],1 });
		else // 앞서 나온 수라면 개수만 증가 시키기
			mapp[sang[i]] += 1;
	}
	
	while (!q.empty())
	{
		binary(q.front());
		q.pop();
	}

	return 0;
}