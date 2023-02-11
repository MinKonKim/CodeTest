#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;

    int a = total / num;
    int count = 0;
    int j = -1;
    
    for (int i = 0; i < num; i++) // 0 1 2 
    {

        a += i * j;
        total -= (a); // 4
       //cout << total << endl;
        answer.push_back(a);
        j*= -1;
         
    }

    for (int i = 0; i < num-1; i++)
    {
        for (int j = i+1; j < num; j++)
        {
            if (answer[i] > answer[j])
            {
                int temp = answer[j];
                answer[j] = answer[i];
                answer[i] = temp;
            }
        }
    }

    return answer;
}
int main()
{
    vector<int> a = solution(5, 5);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
}