#include <iostream>
#include<queue>

using namespace std;
int used[1000000][3][3]{}; // ��� ���� ����

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
	
	// used���� �־��ֱ�



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

		// �����¿�� ���� �ٲ� �͵��� �־��ֱ� ��ġ�°� ����
		if (x - 1 >= 0 && y >= 0)
		{
			int tmpArr[3][3];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					tmpArr[i][j] = arr[tmp][i][j];
			if (compare(tmpArr, used)) // ����� �� ���� ���̸�
			{

			}
		}
	}

	return 0;
}