#include <string>
#include <vector>
#include <iostream>
using namespace std;


//void Print(vector<int> answer)
//{
//    for (int i = 0; i < answer.size(); i++)
//    {
//        cout << answer[i] << ",";
//    }
//    cout << endl;
//}
void Asc(vector<int>& answer)
{
    for (int i = 0; i < answer.size()-1; i++)
    {
        for (int j = i; j < answer.size(); j++)
        {
            if (answer[i] > answer[j])
            {
                int temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
          
        }
    }
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    vector<int> arr;
    for (int i = 0; i < score.size(); i++)
    {
        if (arr.size() < k)arr.push_back(score[i]);
        else
        {
            int min = arr[0];
            int max = arr[k - 1];
            if (score[i] > min)
            {
                arr[0] = score[i];
            }
        }
        Asc(arr);
       // Print(arr);
        cout << arr[0] << endl;
        answer.push_back(arr[0]);
    }

    return answer;
}

int main()
{
    vector<int> arr = { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 };
    vector<int> a;
    a=  solution(4,arr);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ", ";
    }
    cout << endl;
}