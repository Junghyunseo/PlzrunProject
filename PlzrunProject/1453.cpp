#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N, ans = 0;
	bool arr[101]{};
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (!arr[tmp])
			arr[tmp] = true;
		else
			ans++;
	}
	cout << ans;
	return 0;
}