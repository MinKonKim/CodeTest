#include <string>
#include <vector>
#include <set>

using namespace std;

int cnt = 0;
set<int> arr;

bool isPrime(int n)
{
    if (n == 1 || n == 0)return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void bfs(string n, string numbers)
{
    if (n.size() > 0)
    {
        int in = stoi(n);
        arr.insert(in);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        bfs(n + numbers[i], numbers.substr(0,i)+numbers.substr(i+1));
    }
}

int solution(string numbers) 
{
    int answer = 0;
    bfs("", numbers);

    for (auto it = arr.begin(); it !=arr.end(); it++)
    {
        if (isPrime(*it))
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    string numbers = "17";

    cout << solution(numbers) << endl;

}