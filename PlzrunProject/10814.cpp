#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int x;
	string y;
	vector<tuple<int, int, string>> v; // Ʃ���� ���. pair�� Ȯ���̶� �����ϸ� �� ��

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x, i, y });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		auto [x, k, y] = v[i]; // i��° Ʃ���� �����Ͽ� ������ ��Ҹ� x, k, y ������ �Ҵ�
		// �� ������� auto &[x,k,y]�� �ϸ� ���� �ٲ� �� ����.
//int x = std::get<0>(v[i]); �ƴϸ� �̷��� �ؾ� ��
//int k = std::get<1>(v[i]);
//string y = std::get<2>(v[i]);
		cout << x << ' ' << y << '\n';
	}

	return 0;
}