#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int Max = 0;
	vector<int> v;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 1; ; i++)
	{
		int tmpMax = 0;
		for (int j = 0; j < N; j++)
			if (i <= v[j])
				tmpMax += i;
		if (!tmpMax)
			break;
		if (Max < tmpMax)
			Max = tmpMax;
	}
	cout << Max;

	return 0;
}