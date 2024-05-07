#include <iostream>
#include<vector>
#include<string>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int cnt = 1;
	while (1) // 시나리오 개수만큼 반복
	{
		int N;
		cin >> N;
		cin.ignore();

		if (!N)
			break;

		vector<pair<string, int>> vs;

		for (int i = 0; i < N; i++)
		{
			string tmp;
			getline(cin, tmp);
			vs.push_back({ tmp,0 });
		}

		for (int i = 0; i < 2 * N - 1; i++)
		{
			//cout << "!@3";
			int tmp;
			char ch;
			cin >> tmp >> ch;
			vs[tmp - 1].second++;
		}
		cout << "asdfad" << '\n';
		for (int i = 0; i < N; i++)
		{
			if (vs[i].second == 1)
				cout << cnt << ' ' << vs[i].first << '\n';
		}
		while (!vs.empty())
			vs.pop_back();
		cnt++;
	}

	return 0;
}