#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	
	int arr[50][2]{};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i][0];
	int cnt = 0;
	for (int i = 1; i < 1001; i++)
		for (int j = 0; j < N; j++)
			if (arr[j][0] == i)
				arr[j][1] = cnt++;
	for (int i = 0; i < N; i++)
		cout << arr[i][1] << ' ';
	return 0;
}