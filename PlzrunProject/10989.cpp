#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int main(void) // 정렬이라는 단어만 보고 sort를 생각하면 안된다. 메모리 제한이 있으므로 잘 생각해야 함.
{
	cin.tie(0)->sync_with_stdio(0);

	int n, num;
	int arr[2][10001]; // arr[1][k]에는 숫자 몇 번 사용되었는지 저장
	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < 10001; i++) // 숫자를 이렇게 굳이 저장하지 않아도 됨,, 인덱스 자체가 숫자니까
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