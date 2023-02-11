#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int cnt = 0;
    while (cnt < A.size())
    {
        if (A == B)
        {
            answer = cnt;
            break;
        }
        else if(A!=B)
        {
            string temp;
            for (int i = 0; i < A.size(); i++)
            {
                int index = i - 1;
                if (index < 0)index = A.size() - 1;
                
                temp += A[index];

            }
            A = temp;
            cnt++;
            if (cnt == A.size())
            {
                answer = -1;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution("hello", "ohell") << endl;
    cout << solution("apple", "elppa") << endl;
    cout << solution("abc", "abc") << endl;
}