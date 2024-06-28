#include<iostream>

using namespace std;

int N, M;
int arr[101]{};
int tmpArr[101]{};
void sw(int a, int b)
{
	for (int i = a; i < b + 1; i++)
		tmpArr[i] = arr[i];
	int j = 0;
	int cnt = 0;
	for (int i = a; cnt < b - a + 1; i++)
	{
		arr[i] = tmpArr[b - j++];
		cnt++;
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < 101; i++)
		arr[i] = i;
	int num1, num2;
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		sw(num1, num2);
	}
	for (int i = 1; i < N + 1; i++)
		cout << arr[i] << ' ';
	return 0;
}