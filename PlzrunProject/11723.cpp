#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int M, arr[21]{};
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		string tmp;
		int num;
		cin >> tmp;
		if (tmp == "add")
		{
			cin >> num;
			arr[num] = 1;
		}
		else if (tmp == "remove")
		{
			cin >> num;
			arr[num] = 0;
		}
		else if (tmp == "check")
		{
			cin >> num;
			cout << arr[num] << '\n';
		}
		else if (tmp == "toggle")
		{
			cin >> num;
			if (arr[num])
				arr[num] = 0;
			else
				arr[num] = 1;
		}
		else if (tmp == "all")
			for (int j = 1; j < 21; j++)
				arr[j] = 1;
		else
			for (int j = 1; j < 21; j++)
				arr[j] = 0;
	}
	return 0;
}