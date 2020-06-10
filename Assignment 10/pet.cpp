#include<iostream>
#include<string>
#include "pet.h"
using namespace std;

class petImp
{
public:
	petImp(string n);	
	string Name();
	virtual string makeSound();

protected:
	string name;
};

petImp::petImp(string n)
{
	name = n;
}

string petImp::Name()
{
	return name;
}

string petImp::makeSound()
{
	return "";
}

class catImp : public petImp
{
public:
	catImp(string s);
	string makeSound();

private:

};

catImp::catImp(string n) : petImp(n)
{
}

string catImp::makeSound()
{
	return "miau";
}

class dogImp : public petImp
{
public:
	dogImp(string n);
	string makeSound();

private:

};

dogImp::dogImp(string n) : petImp(n)
{
}

string dogImp::makeSound()
{
	return "won";
}


pet::pet(string n)
{
	impl = new petImp(n);
}

string pet::Name()
{
	return impl->Name();
}

string pet::makeSound()
{
	return impl->makeSound();
}

cat::cat(string n) : pet(n)
{
	impl = new catImp(n);
}

dog::dog(string n) : pet(n)
{
	impl = new dogImp(n);
}