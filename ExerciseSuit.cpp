#include <string>
#include <vector>

#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    int num = 0;
    vector<bool>CanEx(n, true);
    vector<bool>CanRent(n, false);
    for (int i = 0; i < lost.size(); i++)
    {
        int idx = lost[i] - 1; //0-4
        CanEx[idx] = false;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        int idx = reserve[i] - 1;
        if (CanEx[idx] == false)
        {
            continue;
        }
        CanRent[idx] = true;
    }
 
    for (int i = 0; i < n; i++)
    {
        int prev = i - 1;
        int back = i + 1;

        if (prev < 0)prev = 0;
        if (back > n - 1)back = n - 1;

        if (!CanEx[i])
        {
            if (CanRent[prev])
            {
                CanEx[i] = true;
                CanRent[prev] = false;
            }
            else if (CanRent[back])
            {
                CanEx[i] = true;
                CanRent[back] = false;
            }
            else continue;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (CanEx[i])answer++;
    }

    return answer;
}
int main()
{
    vector<int> a = { 2,3,4};
    vector<int> b = { 1,2,3,6 };


    cout << solution(6, a, b) << endl;
}