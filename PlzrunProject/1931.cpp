#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int ans = 0;
	bool st[100002]{}; // 해당 인덱스를 시작 시간으로 하는 회의가 있는지
	bool en[100002]{}; // 해당 인덱스를 끝 시간으로 하는 회의가 있는지
	fill(st, st + 100002, false);
	fill(en, en + 100002, false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b }); // tuple 헤더 써야 함!!!
	}

	sort(v.begin(), v.end()); // 회의 시작 시간이 빠른 순으로 정렬

	ans++; // 맨 처음꺼 일단 선택
	int enen = v[0].second; // 맨 처음 회의의 끝으로 일단 선택 이후 이전 회의의 끝 시간

	for (int i = 1; i < N; i++)
	{
		if (enen <= v[i].first) // 앞의 회의 시간의 끝과 이 회의의 시작이 겹치지 않으면
		{
			ans++;
			enen = v[i].second;
		}
		else // 겹치면
			if (v[i].second < enen) // 앞의 회의가 끝나는 시각과 뒤의 회의가 끝나는 시각 비교, 더 빨리 끝나는 회의 선택
				enen = v[i].second;
	}

	cout << ans;

	return 0;
}