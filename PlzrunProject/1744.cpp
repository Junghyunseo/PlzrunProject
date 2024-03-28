#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> v;
long long plusCount = 0; // 1을 제외한 양수의 개수
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

	for (int i = 0; i < N; ) // 증감은 조건마다 다르게 설정
	{
		if (i == N - 1) // 특수한 경우
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
				plusCount += 1; // 짝수로 바꿔주기 -> 이게 진짜 중요했음. 다음 반복 때 영향을 미침
				//cout << "orange" << '\n';
			}
			else // 둘 다 1보다 클 때
			{
				if (plusCount % 2 == 0)//1보다 큰 양수의 개수가 짝수일 때
				{
					sum += v[i] * v[i + 1];
					i += 2;
				}
				else
				{
					sum += v[i++];
					plusCount += 1; // 짝수로 바꿔주기
				}
			}
		}
	}

	cout << sum;

	return 0;
}