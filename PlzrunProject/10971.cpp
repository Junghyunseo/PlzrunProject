#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
long long arr[11][11]{};
vector<int> v;
bool isTravel = true;

long long dis()
{
	long long dis = 0;
	isTravel = true;

	for (int i = 0; i < N - 1; i++)
	{
		if (!arr[v[i]][v[i + 1]]) // 도시 간 이동이 불가능할 때
		{
			isTravel = false;
			break;
		}
		dis += arr[v[i]][v[i + 1]];
	}
	if (isTravel)
	{
		if (arr[v[N - 1]][v[0]]) // 돌아가는 것도 가능할 때
		{
			dis += arr[v[N - 1]][v[0]]; // 처음으로 다시 돌아가는 것 추가
			return dis;
		}
		else
			return 9223372036854775807;
	}
	else
		return 9223372036854775807;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	long long min = 9223372036854775807;

	cin >> N;
	for (int i = 1; i < N + 1; i++)
		for (int j = 1; j < N + 1; j++)
			cin >> arr[i][j];
	for (int i = 1; i < N + 1; i++)
		v.push_back(i);

	do
	{
		if (min > dis())
				min = dis();
	} while (next_permutation(v.begin(), v.end()));

	cout << min;

	return 0;
}