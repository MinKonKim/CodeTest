#include <string>
#include <vector>
#include <iostream>

using namespace std;

float incline(vector<int>dot1, vector<int>dot2)
{
    float y = dot1.back() - dot2.back();
    
    dot1.pop_back(); dot2.pop_back();

    float x = dot1.back() - dot2.back();
    
    float angle = y / x;

    return angle;
}

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    if (incline(dots[0], dots[1]) == incline(dots[2], dots[3]))
    {
        answer = 1;
    }
    else if(incline(dots[0], dots[2]) == incline(dots[1], dots[3]))
    {
        answer = 1;
    }
    else if (incline(dots[0], dots[3]) == incline(dots[1], dots[2]))
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }


    return answer;
}
int main()
{
    vector<vector<int>> dots = { {4, 4},{9, 2},{3, 8},{11, 6} };

    cout << solution(dots) << endl;
}