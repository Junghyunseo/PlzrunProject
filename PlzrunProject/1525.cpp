#include <iostream>
#include<queue>

using namespace std;
int used[1000000][3][3]{}; // 사용 여부 저장

bool compare(int arr[3][3], int arr2[1000000][3][3])
{

}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	queue<int> q;

	int goal[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,0}
	};
	int arr[1000000][3][3]{};

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[0][i][j];
	
	// used에도 넣어주기



	q.push(0);

	int num = 1;

	while (!q.empty())
	{
		int tmp = q.front();
		int x, y;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (arr[tmp][i][j] == 0)
				{
					x = i;
					y = j;
				}
			}
		}
		q.pop();

		// 상하좌우와 값을 바꾼 것들을 넣어주기 겹치는거 빼고
		if (x - 1 >= 0 && y >= 0)
		{
			int tmpArr[3][3];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					tmpArr[i][j] = arr[tmp][i][j];
			if (compare(tmpArr, used)) // 사용한 적 없던 것이면
			{

			}
		}
	}

	return 0;
}