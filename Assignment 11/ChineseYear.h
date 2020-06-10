#ifndef CHINESEYEAR
#define CHINESEYEAR

#include<iostream>
#include <string>
using namespace std;

string Animal[12] = { "Rat", "Ox", "Tiger", "Rabbit", "Dragon",
	"Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig" };

class ChineseYear
{
	friend ostream &operator<<(ostream &output, ChineseYear c)
	{
		cout << c.animal << " " << c.year << "-" << c.year + 1;
		return output;
	}
	friend ChineseYear operator+(ChineseYear &c, int num)
	{
		ChineseYear buffer(c.year + num);
		return buffer;
	}

	friend ChineseYear operator+(int num, ChineseYear &c)
	{
		ChineseYear buffer(c.year + num);
		return buffer;
	}

public:
	ChineseYear()
	{
		animal = "Dog";
		year = 2018;

	}
	ChineseYear(string s)
	{
		animal = s;

		for (int i = 0; i < 12; i++)
		{
			if (animal == Animal[i])
			{
				year = 2008 + i;
				return;
			}
		}
		throw WrongChineseYear("Invalid Chinese Year");
	}
	ChineseYear(int y)
	{
		year = y;

		if (year < 1900)
		{
			throw  WrongGregorianYear("Invalid Gregorian Year (must be >= 1900)");
		}

		animal = Animal[(year - 1900) % 12];
	}
	
	ChineseYear operator+=(int num)
	{
		year += num;
		animal = Animal[(year - 1900) % 12];
		return *this;
	}

	~ChineseYear() {}


	class WrongGregorianYear
	{
	public:
		WrongGregorianYear(string e) : error(e){}
		string what()
		{
			return error;
		}

	private:
		string error;

	};

	class WrongChineseYear
	{
	public:
		WrongChineseYear(string e) : error(e) {}
		string what()
		{
			return error;
		}

	private:
		string error;

	};


private:
	string animal;
	int year;
};


#endif