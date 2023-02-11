#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for (char ch : s)
    {
        for (int i = 0; i < index; i++)
        {
            ch += 1;
            if (ch > 'z')ch = 'a';
            for (char ch2 : skip)
            {
                if (ch == ch2)
                {
                    i--;
                    break;
                }
            }
        }

        answer.push_back(ch);
    }
    return answer;
}

int main()
{
    cout << solution("aukks", "wbqd", 5) << endl;
}