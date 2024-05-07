#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	int Dasom;
	vector<int> v;
	cin >> N;
	cin >> Dasom;
	for (int i = 0; i < N - 1; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	int ans = 0;
	while (!v.empty())
	{
		sort(v.begin(), v.end());
		if (Dasom <= v.back())
		{
			Dasom++;
			v.back() -= 1;
			ans++;
		}
		else
			break;
	}
	cout << ans;

	return 0;

}