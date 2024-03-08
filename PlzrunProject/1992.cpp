#include<iostream>

using namespace std;
int N;
int arr[64][64]{};

void quad(int a, int b, int width)
{
	int sum = 0; // width x width �ȿ� ���� ��ǥ�� �ش��ϴ� ���ڿ� ���� ���� �� �� �ִ���
	for (int i = 0; i < width; i++)
		for (int j = 0; j < width; j++)
			if (arr[a + i][b + j] == arr[a][b]) // arr[a][b]: ���� ��ǥ�� ����
				sum++;
	if (sum == width * width) // �ش� ���� ���� ��� ���ڰ� ���� ��� ������ ���
	{
		cout << arr[a][b];
	}
	else // �ش� ���� ���� �ٸ� ���ڰ� ���� ��� �ɰ��� �˻��ϱ�
	{
		cout << '(';
		quad(a, b, width / 2);
		quad(a, b + width / 2, width / 2);
		quad(a + width / 2, b, width / 2);
		quad(a + width / 2, b + width / 2, width / 2);
		cout << ')';
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j] - '0';
	}

	quad(0, 0, N);

	return 0;
}