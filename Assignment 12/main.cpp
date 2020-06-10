//¹ê§@°ïÅ|§PÂ_¹ïºÙ
#include<iostream>
#include<string>
#include"StackType.h"
using namespace std;

int main()
{
	int cases = 7;
	while (cases--)
	{
		string s;
		StackType S;
		getline(cin, s, '\n');

		for (size_t i = 0; i <= s.size(); i++)
		{
			if (i == s.size())
			{
				if (S.IsEmpty())
					cout << "Well formed" << endl;
				else
					cout << "Not well formed" << endl;
				
			}

			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				S.Push(s[i]);
				continue;
			}

			if (s[i] == ')')
			{
				if (S.IsEmpty() || S.Top() != '(')
				{
					cout << "Not well formed" << endl;
					break;
				}
				else
				{
					S.Pop();
					continue;
				}
			}

			if (s[i] == ']')
			{
				if (S.IsEmpty() || S.Top() != '[')
				{
					cout << "Not well formed" << endl;
					break;
				}
				else
				{
					S.Pop();
					continue;
				}
			}

			if (s[i] == '}')
			{
				if (S.IsEmpty() || S.Top() != '{')
				{
					cout << "Not well formed" << endl;
					break;
				}
				else
				{
					S.Pop();
					continue;
				}
			}
		}

	}
	system("pause");
}