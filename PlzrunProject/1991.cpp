#include <iostream>
#include <vector>

using namespace std;

int L[27]{};
int R[27]{};

void pre(int num)
{
	char ch;
	ch = num + 'A';
	cout << ch;
	if (L[num] != -1) // 왼쪽 자식이 있으면
		pre(L[num]);
	if (R[num] != -1)
		pre(R[num]);
}

void in(int num)
{
	char ch;
	ch = num + 'A';
	if (L[num] != -1) // 왼쪽 자식이 있으면
	{
		in(L[num]);
	}
	cout << ch;
	if (R[num] != -1) // 오른쪽 자식이 있으면 
	{
		in(R[num]);
	}
}

void post(int num)
{
	char ch;
	ch = num + 'A';
	if (L[num] != -1) // 왼쪽 자식이 있으면
	{
		post(L[num]);
	}
	if (R[num] != -1) // 오른쪽 자식이 있으면 
	{
		post(R[num]);
	}
	cout << ch;
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
		pre(0);
		cout << '\n';
		in(0);
		cout << '\n';
		post(0);
	}
	return 0;
}