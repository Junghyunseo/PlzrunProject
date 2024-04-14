#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	vector<string> vs;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		vs.push_back(tmp);
	}
	sort(vs.begin(), vs.end());

	int max = 0;
	int tmpCnt = 0;
	int maxIdx = 0;

	for (int i = 0; i < N - 1; i++)
	{
		if (vs[i] == vs[i + 1])
			tmpCnt++;
		else
		{
			if (max < tmpCnt)
			{
				maxIdx = i - 1;
				max = tmpCnt;
			}
			tmpCnt = 0;
		}
		if (i == N - 2)
		{
			if (max < tmpCnt)
			{
				maxIdx = i;
				max = tmpCnt;
			}
		}
	}
	cout << vs[maxIdx];


	return 0;
}