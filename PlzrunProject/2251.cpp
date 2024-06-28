#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[3]{};
vector<int> v;
int A, B, C;

void spill(int a, int b)
{
	if (b == 0)
	{
		if (A - arr[b] >= arr[a]) // b를 a에 다 부을 수 있는 경우
		{
			arr[b] += arr[a];
			arr[a] = 0;
		}
		else
		{
			arr[a] -= (A - arr[b]);
			arr[b] = A;
		}
	}
	else if (b == 1)
	{
		if (B - arr[b] >= arr[a]) // b를 a에 다 부을 수 있는 경우
		{
			arr[b] += arr[a];
			arr[a] = 0;
		}
		else
		{
			arr[a] -= (B - arr[b]);
			arr[b] = B;
		}
	}
	else
	{
		if (C - arr[b] >= arr[a]) // b를 a에 다 부을 수 있는 경우
		{
			arr[b] += arr[a];
			arr[a] = 0;
		}
		else
		{
			arr[a] -= (C - arr[b]);
			arr[b] = C;
		}
	}
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> A >> B >> C;

	v.push_back(C);

	arr[2] = C;

	if (arr[1] < arr[2])
	{
		arr[1] = B;
		arr[2] -= B;
	}
	else
	{
		arr[1] = C;
		arr[2] = 0;
	}

	// spill(3, 2);
	v.push_back(arr[2]);

	int cnt = 0;
	while (1)
	{
		spill(2, 0);
		//cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] <<"!@#$"<< '\n';
		spill(1, 2);
		//cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';
		spill(0, 1);
		//cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << '\n';

		if (arr[0] == 0)
			v.push_back(arr[2]);
		else
			break;
		cnt++;
		if (cnt > 1000)
			break;
	}
	sort(v.begin(), v.end()); // 중복 제거 하기
	v.erase(unique(v.begin(),v.end()),v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	return 0;
}