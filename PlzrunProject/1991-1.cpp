#include <iostream>
#include <vector>

using namespace std;

int L[27]{};
int R[27]{};

string pre = "";
string in = "";
string post = "";

void trav(int num)
{
	char ch;
	ch = num + 'A';
	pre += ch;
	if (L[num] != -1) // 왼쪽 자식이 있으면
		trav(L[num]);
	in += ch;
	if (R[num] != -1) // 오른쪽 자식이 있으면 
		trav(R[num]);
	post += ch;
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (b == '.')
			L[a - 'A'] = -1;
		else
			L[a - 'A'] = b - 'A';
		if (c == '.')
			R[a - 'A'] = -1;
		else
			R[a - 'A'] = c - 'A';
	}

	if (L[0] == -1 && R[0] == -1)
		cout << "A";
	else
	{
		trav(0);
		cout << pre << '\n' << in << '\n' << post;
	}
	return 0;
}