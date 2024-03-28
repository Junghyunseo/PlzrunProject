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
	bool st[100002]{}; // �ش� �ε����� ���� �ð����� �ϴ� ȸ�ǰ� �ִ���
	bool en[100002]{}; // �ش� �ε����� �� �ð����� �ϴ� ȸ�ǰ� �ִ���
	fill(st, st + 100002, false);
	fill(en, en + 100002, false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b }); // tuple ��� ��� ��!!!
	}

	sort(v.begin(), v.end()); // ȸ�� ���� �ð��� ���� ������ ����

	ans++; // �� ó���� �ϴ� ����
	int enen = v[0].second; // �� ó�� ȸ���� ������ �ϴ� ���� ���� ���� ȸ���� �� �ð�

	for (int i = 1; i < N; i++)
	{
		if (enen <= v[i].first) // ���� ȸ�� �ð��� ���� �� ȸ���� ������ ��ġ�� ������
		{
			ans++;
			enen = v[i].second;
		}
		else // ��ġ��
			if (v[i].second < enen) // ���� ȸ�ǰ� ������ �ð��� ���� ȸ�ǰ� ������ �ð� ��, �� ���� ������ ȸ�� ����
				enen = v[i].second;
	}

	cout << ans;

	return 0;
}