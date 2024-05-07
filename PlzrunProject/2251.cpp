#include <iostream>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int arr[2]{};
	vector<int> v;
	int A, B, C;
	cin >> A >> B >> C;
	v.push_back(C);
	arr[2] = C;

	if (B < C)
	{
		while (1)
		{
			arr[1] = B;
			arr[2] -= arr[1];
			v.push_back(arr[2]);

			arr[0];
		}
	}
	else if (A < C)
	{

	}
	else
		;// do nothing


	return 0;
}