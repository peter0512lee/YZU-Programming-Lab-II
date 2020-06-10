#include<iostream>
#include<string>
#include"person.h"

using namespace std;

// constructor
person::person(char const* nm, int ae)
{
	name = new char[strlen(nm) + 1];
	strcpy_s(name, strlen(nm)+1, nm);
	name[strlen(nm)]= '\0';
	age = ae;

}

// copy constructor
person::person(person& m)
{
	name = new char[strlen(m.name) + 1];
	strcpy_s(name, strlen(m.name) + 1, m.name);
	name[strlen(m.name) ] = '\0';
	age = m.age;
}

// destructor
person::~person()
{
	delete[] name;
}

// assignment operator
person& person::operator=(person& m)
{
	delete[] name;
	name = new char[strlen(m.name) + 1];
	strcpy_s(name, strlen(m.name) + 1, m.name);
	name[strlen(m.name) ] = '\0';
	age = m.age;

	return *this;

}

// member functions
void person::setName(char const* nm)
{
	delete[] name;
	name = new char[strlen(nm) + 1];
	strcpy_s(name, strlen(nm) + 1, nm);
	name[strlen(nm) ] = '\0';

}

void person::setAge(int ae)
{
	age = ae;

}

string person::getName()
{
	string nm;
	
	nm = name;

	return nm;

}

int person::getAge()
{
	return age;
}