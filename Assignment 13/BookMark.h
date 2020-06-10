#pragma once
#ifndef BOOKMARK_H
#define BOOKMARK_H

#include<iostream>
#include<string>
#include <fstream>
#include <vector>

using namespace std;

class BookMark 
{
public:
	BookMark(){}
	BookMark(BookMark &a)
	{
		name = a.name;
		URL = a.URL;

		for (int i = 0; i < a.Tags.size(); i++)
			Tags.push_back(a.Tags[i]);

		Comment = a.Comment;
	
	}
	
	virtual bool folder()
	{
		return 0;
	}

	virtual void setName()
	{
		
		getline(cin, name, '\n');
		
	}
	void setURL()
	{
		getline(cin, URL, '\n');
		
	}
	void setTags()
	{
		Tags.clear();
		string t;
		string b("#");

		
		getline(cin, t, '\n');
		
		for (int i = 0; i < t.size(); i++)
			if (t[i] != ','&&t[i + 1] != ' ')
				b.push_back(t[i]);
			else
			{
				Tags.push_back(b);
				b = "#";
				i += 1;
			}

		Tags.push_back(b);
		
	}
	void setComment()
	{
		
		getline(cin, Comment, '\n');
	}

	virtual string getName()
	{
		return name;
	}
	string getURL()
	{
		return URL;
	}
	void getTags()
	{
		for (int i = 0; i < Tags.size(); i++)
			cout << Tags[i] << " ";
	}
	void getComment()
	{
		cout <<  Comment ;
	}

	bool SearchTags(string c)
	{

		for (int i = 0;i < Tags.size(); i++)
			if (Tags[i] == ('#' + c))
				return 1;

		return 0;
	}

	virtual void Search(vector< string>  &buffer, string c) {}
	virtual void menu(vector<int>& h) {}

	virtual int getsize() 
	{
		return 0;
	};

	virtual void save(ofstream &file, ofstream &f)
	{
		file << name << " " << URL << " ";
		f << Tags.size();
		for (int i = 0;i < Tags.size(); i++)
			file << Tags[i] << " ";
		file << Comment << " ";
	}
	virtual void load(ifstream& file, ifstream& f)
	{
		getline(file, name, ' ');
		getline(file, URL, ' ');
		char a;
		f >> a;
		string bb;
		for (int i = 0;i < (int)(a - '0'); i++)
		{
			getline(file, bb, ' ');
			Tags.push_back(bb);
		}

		getline(file, Comment, ' ');

		
	}
private:
	string name;
	string URL;
	vector<string> Tags;
	string Comment;

};
#endif //BOOKMARK_H
