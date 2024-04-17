#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void)
{
	int arr[500][500]{};
	vector<vector<int>> v;
	vector<int> tmpV;
	vector<pair<int, int>> ansV;
	int N, M, B;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			cin >> tmp;
			tmpV.push_back(tmp);
		}
		v.push_back(tmpV);
		while (!tmpV.empty())
			tmpV.pop_back();
	}

	int max = 0;
	for (int i = 0; i < N; i++) // 최대 층 구하기 
		for (int j = 0; j < M; j++)
			if (max < v[i][j])
				max = v[i][j];

	for (int i = max; i >= 0; i--)
	{
		int big = 0, small = 0;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (i < v[j][k])
					big += (v[j][k] - i);
				else if (i > v[j][k])
					small += (i - v[j][k]);
				else
					continue;
			}
		}

		if (B + big >= small)
		{
			int time = big * 2 + small;
			ansV.push_back({ time,i});
		}
	}
	sort(ansV.begin(), ansV.end());
	int idx = 0;
	for (int i = 1; ; i++)
	{
		if (ansV[0].first == ansV[i].first)
			idx = i;
		else
			break;
	}
	cout << ansV[idx].first << ' ' << ansV[idx].second;
	return 0;
}