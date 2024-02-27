#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main(void) // �����̶�� �ܾ ���� sort�� �����ϸ� �ȵȴ�. �޸� ������ �����Ƿ� �� �����ؾ� ��.
{
	cin.tie(0)->sync_with_stdio(0);

	int n, num;
	int arr[2][10001]; // arr[1][k]���� ���� �� �� ���Ǿ����� ����
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < 10001; i++) // ���ڸ� �̷��� ���� �������� �ʾƵ� ��,, �ε��� ��ü�� ���ڴϱ�
		arr[0][i] = i;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[1][num] += 1;
	}

	for (int i = 1; i < 10001; i++)
	{
		while (arr[1][i])
		{
			cout << arr[0][i] << '\n';
			arr[1][i]--;
		}
	}
	return 0;

}