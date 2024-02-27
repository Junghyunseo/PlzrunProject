#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> v(10002);
vector<vector<pair<int, int>>> v2(10002);

int maxIndex = 0;
int dis[10002]{};
int first;


void dfs(int num)
{
	while (!v[num].empty())
	{
		int toVisit = v[num].back().first;
		int between = v[num].back().second;

		v[num].pop_back();

		if (!dis[toVisit] && toVisit != first) // 처음 들어온 애는 거리가 무조건 0으로 해야함 자기 자신과의 거리이므로
			dis[toVisit] += dis[num] + between;

		//cout << toVisit << ' ' << between << " dis: " << dis[toVisit] << '\n';

		dfs(toVisit);
	}
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int p, c, d; // 부모, 자식, 가중치
		cin >> p >> c >> d;
		v[p].push_back({ c,d });
		v[c].push_back({ p,d });
		v2[p].push_back({ c,d });
		v2[c].push_back({ p,d });
	}
	first = 1;
	dfs(1);

	int max = 0;
	for (int i = 2; i < n + 1; i++)
		if (max < dis[i])
		{
			max = dis[i];
			maxIndex = i;
		}

	fill(dis, dis + 10002, 0); // dis 초기화

	v.resize(v2.size());
	copy(v2.begin(), v2.end(), v.begin()); // v 되돌리기

	//cout << "maxIndex: " << maxIndex << '\n';

	first = maxIndex;
	dfs(maxIndex);

	for (int i = 2; i < n + 1; i++)
		if (max < dis[i])
			max = dis[i];

	cout << max;

	return 0;
}