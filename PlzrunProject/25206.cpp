#include <iostream>

using namespace std;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);

	string ch;
	double sum = 0;
	double num = 20;
	double tmpSum = 0;

	for (int i = 0; i < 20; i++)
	{
		double tmpNum;
		string tmpChar;

		cin >> ch;
		cin >> tmpNum;
		cin >> tmpChar;

		tmpSum += tmpNum;

		if (tmpChar=="A+")
			sum += tmpNum * 4.5;
		else if(tmpChar=="A0")
			sum += tmpNum * 4.0;
		else if (tmpChar == "B+")
			sum += tmpNum * 3.5;
		else if(tmpChar =="B0")
			sum += tmpNum * 3.0;
		else if (tmpChar == "C+")
			sum += tmpNum * 2.5;
		else if(tmpChar=="C0")
			sum += tmpNum * 2.0;
		else if (tmpChar=="D+")
			sum += tmpNum * 1.5;
		else if(tmpChar =="D0")
			sum += tmpNum * 1.0;
		else if (tmpChar == "F")
			continue;
		else
			tmpSum -= tmpNum;
	}
	cout << sum / tmpSum;

	return 0;
}