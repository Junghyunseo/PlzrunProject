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
    cin.ignore(); // 첫 번째 입력 이후 남은 줄 바꿈 문자를 무시

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
