#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);


	int t, N, M;
	int arr[11]{};
	queue<pair<int, int>> q;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int ans = 0;
		cin >> N >> M;
		for (int j = 0; j < N; j++)
		{
			int tmp;
			cin >> tmp; // tmp: 중요도
			arr[tmp]++; // 해당 중요도의 개수 증가
			if (j == M) // 궁금한 문서의 second: 1
			{
				q.push({ tmp,1 });
			}
			else // 다른 문서의 second: 0
				q.push({ tmp,0 });
		}

		while (!q.empty())
		{
			int a = q.front().first; // 중요도
			int b = q.front().second; // 궁금한 문서인지

			int cnt = 0;
			for (int j = 1; a + j < 10; j++)
			{
				if (!arr[a + j]) // 뒤에 중요도가 높은게 없으면
					cnt++;
			}
			if (cnt == 9 - a) // 뒤에 다 봤을 때 중요도가 더 높은게 하나도 없으면 꺼내기 or 출력하기
			{
				arr[a]--; // 이거 중요도 지우고
				ans++;
				if (b == 1) // 알고싶은거면
				{
					cout << ans << '\n';
					q.pop();
				}
				else
					q.pop(); // 꺼내기
			}
			else // 뒤애 다 봤을 때 중요도가 높은게 하나라도 있으면 맨 뒤로 보내기
			{
				q.push({ a,b });
				q.pop();
			}
		}

	}

	return 0;
}