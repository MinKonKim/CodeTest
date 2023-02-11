#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;
int p1a = 0, p2a = 0, p3a = 0;
vector<int> solution(vector<int> answers) {
    vector<int> answer;

    //5번 주기
    int p1[] = { 1,2,3,4,5 };
    //8번 주기
    int p2[] = { 2,1,2,3,2,4,2,5 };
    //10번 주기
    int p3[] = { 3,3,1,1,2,2,4,4,5,5 };



    for (int i = 0; i < answers.size(); i++)
    {
        if (p1[i%5] == answers[i]) p1a++;
        if (p2[i%8] == answers[i]) p2a++;
        if (p3[i%10] == answers[i]) p3a++;
    }

    int Max = max(max(p1a, p2a),p3a);

    if (p1a == Max)answer.push_back(1);
    if (p2a == Max)answer.push_back(2);
    if (p3a == Max)answer.push_back(3);

    

    return answer;
}
int main()
{

    vector<int> a = { 1,2,3,4,5 };

    a = solution(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "->";
    }
}