#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Caculate(string privacie, vector<string> terms)
{
	string year = privacie.substr(0, 4);  
	string month = privacie.substr(5, 2); 
	string date = privacie.substr(8, 2);  
	string term = privacie.substr(11);    

	string answer="";

	for (size_t i = 0; i < terms.size(); i++)
	{
		if (term == terms[i].substr(0,1))
		{
			int tempmonth = stoi(month) + stoi(terms[i].substr(2));
			int tempyear = stoi(year);
			int tempdate = stoi(date) - 1;


			if (tempmonth > 12)
			{
				tempmonth -= 12;
				tempyear += 1;
			}

			if (tempdate == 0)
			{
				tempdate = 28;
				tempmonth -= 1;
				if (tempmonth == 0)
				{
					tempmonth = 12;
					tempyear -= 1;
				}
			}


			if (tempmonth < 10)
			{
				month ="0"+ to_string(tempmonth);
			}
			else
			{
				month = to_string(tempmonth);
			}
		

			if (tempdate < 10)
			{
				date = "0" + to_string(tempdate);
			}
			else
			{
				date = to_string(tempdate);
			}

			if (tempyear > 2022) tempyear = 2022;
			else if (tempyear < 2000) tempyear = 2000;
			year = to_string(tempyear);

			answer += year; answer += ".";
			answer += month; answer += ".";
			answer += date;

			break;
		}
	}
	

	return answer;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

	cout << "Today : " << today << endl;
	int TodayYear = stoi(today.substr(0, 4));
	int TodayMonth = stoi(today.substr(5, 2));
	int TodayDate = stoi(today.substr(8, 2));  
	
	for (int i = 0; i < privacies.size(); i++)
	{
		cout << privacies[i] << "-->";
		string privacie = Caculate(privacies[i], terms);

		cout << privacie << endl;
		int Year = stoi(privacie.substr(0, 4));
		int Month = stoi(privacie.substr(5, 2));
		int Date = stoi(privacie.substr(8, 2));

		if (Year >= 2000 && Year <= 2022)
		{
			if (Year < TodayYear)
			{
				answer.push_back(i + 1);
			}
			else if (Year == TodayYear)
			{
				if (Month < TodayMonth)
				{
					answer.push_back(i + 1);
				}
				else if (Month == TodayMonth)
				{
					if (Date <= TodayDate-1)
					{
						answer.push_back(i + 1);
					}
				}
			}
		}
	}

    return answer;
}

int main()
{
	string today = "2022.05.19";
	
	vector<string> terms = { "A 6", "B 12", "C 3", "D 4"};

	vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C","2018.12.28 B"};

	vector<int> sol = solution(today, terms, privacies);

	for (int i = 0; i < sol.size(); i++)
	{
		cout << sol[i] << endl;
	}
}