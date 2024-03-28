#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int N;
vector<int> v;

int dif()
{
	int sum = 0;
	for (int i = 0; i < N - 1; i++)
		sum += abs(v[i] - v[i + 1]);
	return sum;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int ans = 0;

	do
	{
		if (ans < dif())
			ans = dif();
	} while (next_permutation(v.begin(), v.end()));

	cout << ans;

	return 0;
}