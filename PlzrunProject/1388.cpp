#include<iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	int merge = 0;
	vector<string> vs;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string tmp;
		cin >> tmp;
		vs.push_back(tmp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if ((vs[i][j - 1] == '-') && (vs[i][j] == '-'))
				merge++;
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 1; j < N; j++)
			if ((vs[j - 1][i] == '|') && (vs[j][i] == '|'))
				merge++;
	}
	cout << N * M - merge;

	return 0;
}