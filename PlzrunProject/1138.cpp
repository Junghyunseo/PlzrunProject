#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	int N;
	vector<int> v;
	list<int> MyList;
	list<int>::iterator it = MyList.begin(); //반복자 선언
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	MyList.push_front(N);
	
	for (int i = N - 2; i >= 0; i--)
	{
		int num = i + 1;
		int isBig = 0;
		bool isDone = false;
		for (it = MyList.begin(); it != MyList.end(); it++)
		{
			if (isBig == v[i])
			{
				MyList.insert(it, num);
				isDone = true;
				break;
			}
			if (*it > num)
				isBig++;
		}
		if(isBig==v[i] && !isDone)
			MyList.insert(MyList.end(), num);
	}
	for (it = MyList.begin(); it != MyList.end(); it++)
	{
		cout << *it << " ";
	}

	return 0;
}