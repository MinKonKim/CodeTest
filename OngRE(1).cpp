#include <string>
#include <vector>
#include <iostream>
using namespace std;

void subsub(string mainstring)
{
    if (mainstring.size() > 15 or mainstring.size()<1)return;
   
    string babble[4] = { "aya", "ye","woo","ma" };
    
}

int solution(vector<string> babbling) 
{
    int answer = 0;
    int next = 0;

    if (babbling.size() < 100)
    {
        for (int i = 0; i < babbling.size(); i++)
        {
            bool check = false;
            for (int j = 0; j < babbling[i].size(); j++)
            {
                if (babbling[i].substr(j, 3) == "aya")j += 2;
                else if (babbling[i].substr(j, 2) == "ye")j += 1;
                else if (babbling[i].substr(j, 3) == "woo")j += 2;
                else if (babbling[i].substr(j, 2) == "ma")j += 1;
                else 
                {
                    check = true;
                    break;
                }
            }

            if (!check)answer++;
        }
        
    }

    return answer;
}



int main()
{
    vector<string> arr = { "ayaye","uuuma","ye","yemawoo","ayaa" };

    cout << solution(arr) << endl;

}