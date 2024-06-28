#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;
    cin.ignore(); // ù ��° �Է� ���� ���� �� �ٲ� ���ڸ� ����

    for (int i = 0; i < T; i++)
    {
        string sentence;
        getline(cin, sentence);
        stringstream ss(sentence);
        string word;

        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            cout << word << ' ';
        }
        cout << '\n';
    }

    return 0;
}
