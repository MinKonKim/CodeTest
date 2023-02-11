#include <vector>
#include <iostream>
using namespace std;

bool isPrimeNumber(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)return false;
    }

    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    int cnt = 0;
    
    for (int i = 0; i < nums.size()-2; i++)
    {
        for (int j = i+1; j < nums.size()-1; j++)
        {
            for (int k = j+1; k < nums.size(); k++)
            {
                if (i == j || j == k || i == k)continue;

                if (isPrimeNumber(nums[i] + nums[j] + nums[k]))
                {
                    answer++;
                    cout << nums[i] <<" " << nums[j] <<" " << nums[k] <<" " << nums[i] + nums[j] + nums[k] << endl;
                }
            }
        }
    }



    return answer;
}
int main()
{
    vector<int> a = { 1,2,3,4 };
    cout << solution(a) << endl;
}