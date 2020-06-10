#include<iostream>

using namespace std;

#include"folder.h"

int main()
{
	vector<int> h;

	ifstream file("asd.txt", ios::in);
	ifstream f("bool.txt", ios::in);
	Folder test("xd");

	test.load(file, f);

	test.menu(h);

	ofstream outfile("asd.txt", ios::binary);
	ofstream of("bool.txt", ios::out);

	

	test.save(outfile, of);

	system("pause");
}