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
	vector<tuple<int, int, string>> v; // 튜플의 사용. pair의 확장이라 생각하면 될 듯

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x, i, y });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		auto [x, k, y] = v[i]; // i번째 튜플을 분해하여 각각의 요소를 x, k, y 변수에 할당
		// 꼭 기억하자 auto &[x,k,y]로 하면 값도 바꿀 수 있음.
//int x = std::get<0>(v[i]); 아니면 이렇게 해야 함
//int k = std::get<1>(v[i]);
//string y = std::get<2>(v[i]);
		cout << x << ' ' << y << '\n';
	}

	return 0;
}