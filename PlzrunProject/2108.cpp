#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

long long N;
long long arr[500000];

void avg()
{
	double sum = 0;

	for (long long i = 0; i < N; i++)
		sum += arr[i];
	
	if (round(sum / N) == -0)
		cout << 0 << '\n';
	else
		cout << round(sum / N) << '\n';
}
void mid()
{
	cout << arr[N / 2] << '\n';
}
void fre()
{
	vector<pair<long long, long long>> v;

	v.push_back({ arr[0],1 });
	
	for (long long i = 1; i < N; i++)
	{
		if (arr[i - 1] == arr[i])
			v.back().second++;
		else
			v.push_back({ arr[i],1 });
	}

	long long max = 0;

	for (long long i = 0; i < v.size(); i++)
		if (max < v[i].second)
			max = v[i].second; // 등장횟수의 최댓값

	queue<long long> q;
	
	for (long long i = 0; i < v.size(); i++)
		if (v[i].second == max)
			q.push(i); // 등장횟수가 최댓값인 인덱스들 넣기

	if (q.size() > 1) // 두번째로 작은 값이 처음으로 오도록
		q.pop();
	cout << v[q.front()].first << '\n';
}
void ran()
{
	cout << arr[N - 1] - arr[0];
}

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);	
	cin >> N;

	for (long long i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	avg();
	mid();
	fre();
	ran();

	return 0;
}