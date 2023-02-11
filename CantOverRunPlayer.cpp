#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";

	unordered_map<string, int> hashmap;
	for (int i = 0; i < participant.size(); i++)
	{
		string name = participant[i];
		if (hashmap.empty())
		{
			hashmap.insert(make_pair(name, 1 ));
		}
		else
		{
			unordered_map<string, int>::iterator iter = hashmap.find(name);
			if (iter != hashmap.end())
			{
				iter->second++;
			}
			else
			{
				hashmap.insert(make_pair(name, 1));
			}
		}
	}

	for (int i = 0; i < completion.size(); i++)
	{
		unordered_map<string, int>::iterator iter = hashmap.find(completion[i]);
		if (iter != hashmap.end())
		{
			iter->second--;
		}
	}

	for (auto iter : hashmap)
	{
		if (iter.second > 0)
		{
			return answer = iter.first;
		}
	}
}

int main()
{
	vector<string> participant = { "mislav", "stanko", "mislav", "ana"};
	vector<string> completion = { "mislav", "stanko", "ana" };

	cout << solution(participant, completion) << endl;

	return 0;
}