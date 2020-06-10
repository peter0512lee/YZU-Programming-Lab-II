#pragma once
#ifndef FOLDER_H
#define FOLDER_H

#include <cstdlib>
#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include"BookMark.h"

using namespace std;

class Folder :public BookMark
{
public:
	Folder()
		:BookMark()
	{
		name = "";
	}

	Folder(string a)
		:BookMark()
	{
		name = a;
	}

	~Folder()
	{
		
	}

	void load(ifstream& file, ifstream& f)
	{

		
		if (name != "")
			name = "";
		else
			getline(file , name,' ');

		for (int i = 0; ; i++)
		{
			char a;
			f >> a;
			
			if (a =='1')
			{
				FolderData.push_back(new Folder);
				FolderData[i]->load(file, f);
			}
			else if(a == '0')
			{

				FolderData.push_back(new BookMark);
				FolderData[i]->load(file, f);

			}
			if (a=='-'|| f.eof())
				return;
		}
	}
	void save(ofstream &file, ofstream &f) 
	{

		if (name != "") 
		{		
			file << name << ' ';
		}
		
		for (int i = 0; i < FolderData.size();i++)
		{
			f << FolderData[i]->folder();
			FolderData[i]->save(file, f);
		}
		f << '-';
	}

	bool folder()
	{
		return 1;
	}

	void setName()
	{
		getline(cin, name, '\n');
		
	}

	string getName()
	{

		return name;
	}

	void Add()
	{

		cout <<
			"[f] add a folder\n" << 
			"[b] add a bookmark\n" <<
			"Please choose one : \n";

		string c;

		getline(cin, c, '\n');

		if (c == "f") 
		{
			Folder *b =nullptr;

			cout << "Please input folder name:\n";

			FolderData.push_back(b);

			FolderData[FolderData.size() - 1] = new Folder;

			FolderData[FolderData.size() - 1]->setName();

			
		}
		else if (c == "b") {
			BookMark *b = nullptr;

			FolderData.push_back(b);

			FolderData[FolderData.size() - 1] = new BookMark;

			cout << "Please input bookmark name:\n";
			FolderData[FolderData.size() - 1]->setName();
			cout << "Please input bookmark url:\n";
			FolderData[FolderData.size() - 1]->setURL();
			cout << "Please input hash tags:\n";
			FolderData[FolderData.size() - 1]->setTags();
			cout << "Please input comments:\n";
			FolderData[FolderData.size() - 1]->setComment();

			
		}
		else
		{
			cout << "input eorry";
			return;
		}
	};
	void Delete(int d) {
		if (FolderData[d]->folder())
		{
			if (FolderData[d]->getsize() == 0)
			{
				cout << " + ";

				cout << FolderData[d]->getName();
				cout << "\nDo you really want to delete this folder? [y for Yes, n for No]\n";
				string b;
				getline(cin, b,'\n');
				if (b =="y")
				{
					for (int i = d;i < FolderData.size() - 1;i++)
						FolderData[i] = FolderData[i + 1];

					FolderData.pop_back();
				}
				else 
					return;
			}
			else {

				cout << "The folder [" << FolderData[d]->getName() << "] is no empty, can not remove it\n";
				return;
			}
		}
		else
		{
			cout << " - ";

			cout << "[" << FolderData[d]->getName() << "]";
			cout << "(";
			cout << FolderData[d]->getURL();
			cout << ")";
			FolderData[d]->getTags();
			cout << "{";
			FolderData[d]->getComment();
			cout << "}";

			cout << "\nDo you really want to delete this bookmark? [y for Yes, n for No]\n";
			string b;
			getline(cin, b, '\n');
			if (b == "y")
			{
				for (int i = d;i < FolderData.size() - 1;i++)
					FolderData[i] = FolderData[i + 1];

				FolderData.pop_back();
			}
			else
				return;

		}

	}
	void Modify(int i)
	{

		if (!FolderData[i]->folder()) {
			cout << "= bookmark Name: ";
			cout << FolderData[i]->getName();
			cout << "\nPlease input new bookmark name:\n";
			FolderData[i]->setName();

			cout << "= bookmark url: ";
			cout << FolderData[i]->getURL();
			cout << "\nPlease input new url:\n";
			FolderData[i]->setURL();

			cout << "= Hash tag: ";
			FolderData[i]->getTags();
			cout << "\nPlease input new hash tag:\n";
			FolderData[i]->setTags();

			cout << "= bookmark comment: ";
			FolderData[i]->getComment();
			cout << "\nPlease input new comment:\n";
			FolderData[i]->setComment();


		}
		else
		{
			cout << "= bookmark Name: ";
			FolderData[i]->getName();
			cout << "\nPlease input new folder name:\n";
			FolderData[i]->setName();

		}


	}
	void Search(vector< string>  &buffer,string c) {
		

		

		for (int b = 1,i = 0; i < FolderData.size(); i++)
			if (FolderData[i]->folder())
				FolderData[i]->Search(buffer,c);
			else
			{
				if (FolderData[i]->SearchTags(c))
				{
				
					buffer.push_back(FolderData[i]->getURL());

					cout << "[" << b << "] - ";

					cout << "[" << FolderData[i]->getName() << "]";
					cout << "(";
					cout << FolderData[i]->getURL();
					cout << ") ";
					FolderData[i]->getTags();
					cout << "{";
					FolderData[i]->getComment();
					cout << "}\n";

					++b;

				}

			}
		return;
	}

	void openSearch(vector< string>  &buffer)
	{
		string chiose;
		if (buffer.size() > 1)
			cout << "Please select [1-" << buffer.size() << "] to open specific bookmark:\n";
		else if (buffer.size() == 1)
			cout << "Please select [1] to open specific bookmark:\n";
		else
			return;

		getline(cin, chiose, '\n');

		cout << "open bookmark url";

		cout << "(";
		cout << buffer[chiose[0] - '1'];
		cout << ") \n";

		string cmd("start chrome ");

		system((cmd + "\"" + buffer[chiose[0] - '1'] + "\"").c_str());

	}
	virtual int getsize()
	{
		return FolderData.size();
	}
	void menu(vector<int>& h)
	{

		while (true)
		{
			cout << "+---------------------------------------------------------------------+\n";

			if (h.size() != 0)
				for (int i = 0;i < h.size();i++)
					cout << "[" << h[i] << "]";

			if (getsize() == 0)
				cout << "[] None\n";
			else
			{
				for (int i = 0;i < getsize();i++)
				{
					
					if (h.size() != 0 && i != 0)
						for (int j = 0;j < h.size(); j++)
							cout << "   ";
						
					cout << "[" << i+1 << "]";
					

					if (FolderData[i]->folder())
					{
						cout << " + ";

						cout << FolderData[i]->getName();
					}
					else
					{
						cout << " - ";
						cout << "[" << FolderData[i]->getName() << "]";
						cout << "(";
						cout << FolderData[i]->getURL();
						cout << ") ";
						FolderData[i]->getTags();
						cout << "{";
						FolderData[i]->getComment();
						cout << "}";
					}
					cout << endl;
				}
			}

			cout << "\n[a] add a folder or bookmark\n"
				<< "[d] delete a folder or bookmark\n"
				<< "[m] modify a folder or bookmark\n"
				<< "[s] use hash tag to search bookmarks\n"
				<< "[b] go back\n\n";

			if (getsize() == 0)
				cout << "Please a,d,m,s,b to do an action:\n";
			else if (getsize() == 1)
				cout << "Please select [1] to a open specific fold or bookmark or [a,d,m,s,b] to do an action:\n";
			else
				cout << "Please select [1-" << getsize() << "] to a open specific fold or bookmark or [a,d,m,s,b] to do an action:\n";

			string ch;
			string c;
			vector< string>  buffer;

			getline(cin, ch, '\n');

			switch (ch[0])
			{
			case 'a':
				Add();
				break;
			case 'd':
				Delete(ch[1]-'1');
				break;
			case 'm':
				Modify(ch[1] - '1');
				break;
			case 's':
				cout << "Please input hash tag:\n";
				
				getline(cin, c, '\n');
				Search(buffer,c);
				openSearch(buffer);
				break;
			case 'b':
				if (h.size() != 0)
					h.pop_back();
				return;
			default:

				if (FolderData[ch[0] - '1']->folder())
				{
					h.push_back(ch[0] - '0');
					FolderData[ch[0] - '1']->menu(h);
				}
				else
				{
					cout << "open bookmark url";

					cout << "(";
					cout << FolderData[ch[0] - '1']->getURL();
					cout << ") \n";

					string cmd("start chrome ");

					system((cmd + "\"" + FolderData[ch[0] - '1']->getURL() + "\"").c_str());
				}
				
				break;
			}
		}
	}

private:
	
	string name;
	vector< BookMark *>  FolderData;


};
#endif //end FOLDER_H