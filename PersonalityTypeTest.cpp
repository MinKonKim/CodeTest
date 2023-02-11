#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string, int>pTable;

string select(string st, int num)
{
    if (num < 4)
    {
        return st.substr(0,1);
    }
    else if(num > 4)
    {
        return st.substr(1);
    }
    else
    {
        return "";
    }
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for (int i = 0; i < survey.size(); i++)
    {
        string st = select(survey[i], choices[i]);
        int point = choices[i] - 4;
        if (point < 0)point *= -1;
        if (st != "")
        {
            cout << st << " : " << point << endl;
            pTable[st]+=point;
        }
    }

    if (pTable["R"] < pTable["T"])
    {
        answer.push_back('T');
    }
    else
    {
        answer.push_back('R');
    }

    if (pTable["C"] < pTable["F"])
    {
        answer.push_back('F');
    }
    else
    {
        answer.push_back('C');
    }

    if (pTable["J"] < pTable["M"])
    {
        answer.push_back('M');
    }
    else
    {
        answer.push_back('J');
    }


    if (pTable["A"] < pTable["N"])
    {
        answer.push_back('N');
    }
    else
    {
        answer.push_back('A');
    }


    return answer;
}

int main()
{
    vector<string> a = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> b = { 5, 3, 2, 7, 5 };

    cout << solution(a, b);


}