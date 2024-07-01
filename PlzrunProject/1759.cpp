#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int L, C;
vector<char> vc;
vector<char> ansVc;

bool isGood()
{
	int isM = 0; // 모음 개수
	int isJ = 0; // 자음 개수
	for (int i = 0; i < L; i++)
	{
		if (ansVc[i] == 'a' || ansVc[i] == 'e' || ansVc[i] == 'i' || ansVc[i] == 'o' || ansVc[i] == 'u')
			isM++;
		else
			isJ++;
	}
	if (isM > 0 && isJ > 1)
		return true;
	else
		return false;
}

void comb(int st)
{
	if (ansVc.size() == L && isGood())
	{
		for (int i = 0; i < L; i++)
			cout << ansVc[i];
		cout << '\n';
		return;
	}
	else
	{
		for (int i = st + 1; i < C; i++)
		{
			ansVc.push_back(vc[i]);
			comb(i);
			ansVc.pop_back();
		}
	}
	return;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> L >> C;

	char tmp;
	for (int i = 0; i < C; i++)
	{
		cin >> tmp;
		vc.push_back(tmp);
	}
	sort(vc.begin(), vc.end());

	comb(-1);

	return 0;
}