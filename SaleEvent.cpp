#include <string>
#include <vector>
#include <map>

#include<iostream>
using namespace std;



int check(map<string, int>listmap, vector<string> &discount, int idx)
{
	for ( int i = idx ; i < idx+10; i++)
	{
		listmap[discount[idx]]--;
		cout<<discount[idx]<<" : "<< listmap[discount[idx]] << endl;
	}

	for (auto it = listmap.begin(); it != listmap.end(); it++)
	{
		if (it->second > 0)return 0;
	}

	return 1;
}


int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
	map<string, int> listmap;

	for (int i = 0; i < number.size(); i++)
	{
		listmap[want[i]] = number[i];
	}

	for (int i = 0; i < discount.size()-9; i++)
	{
		answer += check(listmap, discount, i);
	}
	
    return answer;
}
//int main()
//{
//	vector<string> want = { "banana", "apple", "rice", "pork", "pot" };
//
//	vector<int> number = { 3, 2, 2, 2, 1 };
//
//	vector<string> discount = {"chicken", "apple", "apple", "banana", "rice", 
//							   "apple"  , "pork" , "banana",  "pork", "rice", 
//							   "pot",    "banana", "apple", "banana" };
//
//	cout << solution(want, number, discount) << endl;
//
//}
