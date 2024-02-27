#include <iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int arr[1000001]{};

	for (int i = 2; i < 1001; i++) // 소수는 0으로 만들어 놓기
		if (!arr[i])
			for (int j = 2; i * j < 1000001; j++)
				arr[i * j] = 1;
	int a = 0, b = 0;

	vector<int> v; // 홀수인 소수만 들어있는 벡터

	for (int i = 3; i < 1000001; i++)
		if (!arr[i])
			v.push_back(i);


	while (1)
	{
		int n;
		cin >> n;

		if (!n) // 0이 들어오면 종료
			break;
		else
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (!arr[n - v[i]]) // 에라토스테네스의 체에 있는 소수이면
				{
					a = v[i];
					b = n - v[i];
					break;
				}
				else
					continue;
			}
		}
		if (!a && !b)
			cout << "Goldbach's conjecture is wrong.";
		else
			cout << n << " = " << a << " + " << b << '\n';
	}

	return 0;
}