#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;

	int ans = 665;

	while (n)
	{
		ans++;
		for (int i = 0; ; i++)
		{
			string str = to_string(ans);
			
			if (i > str.size() - 3)
				break;

			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6')
			{
				n--;
				break;
			}
		}

	}

	cout << ans;
	return 0;
}