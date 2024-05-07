#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	long long N, S;
	cin >> N >> S;
	vector<long long> v;
	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int ans = 0;
	for (int i = 1; i < N + 1; i++) // ũ�Ⱑ 1�� �κ� �������� N�� �κ� ����
	{
		for (int j = 0; j + i < N + 1; j++) // �������� 0���� �� ������
		{
			long long sum = 0;
			for (int k = 0; k < i; k++) // �� ���������� ũ�� N��ŭ�� �κм���
				sum += v[j + k];
			cout << sum << ' ';
			if (sum == S)
				ans++;
		}
	}
	cout << ans;
	return 0;
}