#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> v;
long long plusCount = 0; // 1�� ������ ����� ����
long long N, sum = 0;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		if (tmp > 1)
			plusCount++;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; ) // ������ ���Ǹ��� �ٸ��� ����
	{
		if (i == N - 1) // Ư���� ���
			sum += v[i++];
		else
		{
			if ((v[i] < 0 && v[i + 1] < 0) || (v[i] < 0 && v[i + 1] == 0) || (v[i] == 0 && v[i + 1] == 0))
			{
				sum += v[i] * v[i + 1];
				i += 2;
				//cout << "yellow" << '\n';
			}
			else if ((v[i] < 0 && v[i + 1] > 0) || (v[i] == 0 && v[i + 1] > 0) || ((v[i] == 1 && v[i + 1] > 1) && (plusCount % 2 == 0)))
			{
				sum += v[i++];
				//cout << "green" << '\n';
			}
			else if ((v[i] == 1 && v[i + 1] == 1) || ((v[i] == 1 && v[i + 1] > 1) && (plusCount % 2 == 1)))
			{
				sum += v[i];
				sum += v[i + 1];
				i += 2;
				plusCount += 1; // ¦���� �ٲ��ֱ� -> �̰� ��¥ �߿�����. ���� �ݺ� �� ������ ��ħ
				//cout << "orange" << '\n';
			}
			else // �� �� 1���� Ŭ ��
			{
				if (plusCount % 2 == 0)//1���� ū ����� ������ ¦���� ��
				{
					sum += v[i] * v[i + 1];
					i += 2;
				}
				else
				{
					sum += v[i++];
					plusCount += 1; // ¦���� �ٲ��ֱ�
				}
			}
		}
	}

	cout << sum;

	return 0;
}