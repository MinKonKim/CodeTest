#include <string>
#include <vector>
#include <iostream>
using namespace std;



int* CountNum(int Buf[], string X)
{
    for (int i = 0; i < X.size(); i++)
    {
        Buf[X[i] - '0']++;
    }
   
    return Buf;
}

string solution(string X, string Y) {

    string answer = "";
    int Xbuf[10] = { 0, };
    int Ybuf[10] = { 0, };

    if (X[0] == '0' || Y[0] == '0')return answer = "-1";
    if (X.length() > 3000000)return answer = "-1";

    CountNum(Xbuf, X);
    CountNum(Ybuf, Y);
    for (int i = 9; i >=0; i--)
    {
        int num = min(Xbuf[i], Ybuf[i]);
        for (int j = 0; j < num; j++)
        {
            answer += to_string(i);
        }
        
    }

    if (answer == "") return answer = "-1";
    else if (answer[0] == '0')return answer = "0";
    else return answer;

}

//int main()
//{
//    cout << solution("100", "2345") << endl;
//    cout << solution("100", "203045") << endl;
//    cout << solution("100", "123450") << endl;
//    cout << solution("12321", "42531") << endl;
//    cout << solution("5525", "1255") << endl;
//}