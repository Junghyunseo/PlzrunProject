#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> v;
stack<int> s;
int visit[100001]{};
int top; // 사이클 마지막, 중복되는 것 처음이자 끝

void dfs(int num)
{
	if (!visit[num])
	{
		s.push(num);
		visit[num] = 1;
		dfs(v[num]);
	}
	else
		top = num; // 사이클 마지막
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	int min = 0; // 팀 없는 학생

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		v.push_back(0); // index 0 안 씀
		for (int i = 0; i < n; i++)
		{
			int stu;
			cin >> stu;
			v.push_back(stu);
		}

		for (int i = 1; i < v.size(); i++)
		{
			if (!visit[i])
			{
				s.push(i);
				visit[i] = 1;
				dfs(v[i]);
			}

			int check = 0;
			int uu = 0;

			while (!s.empty())
			{

				if (s.top() == top)
				{
					check++;
					s.pop();
					break;
				}
				else
				{
					s.pop();
					uu++;
				}
			}
			if (!check)
				min += uu;
			else
				min += s.size();
			while (!s.empty())
				s.pop();
		}

		cout << min << '\n';

		// 초기화하기
		while (!v.empty())
			v.pop_back();
		min = 0;
		fill(visit, visit + 100001, 0);
	}

	return 0;
}