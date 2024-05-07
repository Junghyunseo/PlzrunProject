#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	vector<long long> v;
	long long price = 1;
	long long income = 0;
	long long N, M;
	cin >> N >> M;
	for (long long i = 0; i < M; i++)
	{
		long long tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	if (N < M)
	{
		sort(v.begin(), v.end(), comp); // 내림차순 정렬
		//뒤에 자르기
		for (int i = N; i < M; i++)
			v[i] = 0;
	}
	bool isPossible = true;
	long long maxIncome = 0;
	long long ansPrice = 10000000;
	
	while(isPossible)
	{
		isPossible = false;
		long long tmpIncome = 0;
		for (long long i = 0; i < v.size(); i++)
		{
			if (v[i] >= price)
			{
				tmpIncome += price;
				isPossible = true;
			}
		}
		if (tmpIncome > maxIncome)
		{
			maxIncome = tmpIncome;
			ansPrice = price;
		}
		price++;
	}
	cout << ansPrice << ' ' << maxIncome;

	return 0;
}