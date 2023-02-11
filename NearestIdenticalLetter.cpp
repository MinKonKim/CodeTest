#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
	vector<bool> check(s.size(),false);
	//  문자  인덱스
	answer.push_back(-1);
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (s[i] == s[j]&&i>j && !check[j])
			{
				answer.push_back(i - j);
				check[j] = true;
				break;
			}
			else if(j == i-1)
			{
				answer.push_back(-1);
			}
		}

	}

    return answer;
}

/* 좋은 답인듯
vector<int> solution(string s) {
	vector<int> answer;
	vector<int> alpha(26,-1);
	for(int i=0;i<s.length();i++){
		if(alpha[s[i]-'a']==-1)answer.push_back(-1);
		else answer.push_back(i-alpha[s[i]-'a']);
		alpha[s[i]-'a']=i;
	}
	return answer;
}





*/
int main()
{

	string s = "wwwwawww";

	vector<int> a = solution(s);
	cout << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout<< a[i] << "  ";
	}

}