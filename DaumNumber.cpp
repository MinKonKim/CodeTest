#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> common) 
{
    bool isPlus = false;
    int answer = 0;
    if (common.size() < 1000)
    {
        int plus,plus2, div,div2;

        plus = common[1] - common[0];
        plus2 = common[2] - common[1];

        if (plus == plus2)
        {
            isPlus = true;
        }
        else
        {
            div = common[1] / common[0];
            div2 = common[2] / common[1];

            if (div == div2)
            {
                isPlus = false;
            }
        }

        if (isPlus)
        {
            answer = common.back() + plus;
        }
        else
        {
            answer = common.back() * div;
        }

    }


    return answer;
}

int main()
{
    vector<int> common = { 1,2,3,4 };

    cout << solution(common) << endl;
}