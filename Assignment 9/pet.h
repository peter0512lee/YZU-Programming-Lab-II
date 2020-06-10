#pragma once
#ifndef PET_H
#define PET_H
#include<iostream>
#include<string>
using namespace std;
class pet
{
public:
	pet(string s) : name(s) {}
	~pet() {}
	string Name() 
	{
		return name;
	}
	virtual string makeSound() 
	{
		return "";
	}

private:
	string name;
};

class cat : public pet
{
public:
	cat(string s) : pet(s) {}
	~cat() {}
	
	string makeSound()
	{ 
		return "miau"; 
	}

private:

};

class dog : public pet
{
public:
	dog(string s) : pet(s) {}
	~dog() {}
	
	string makeSound() 
	{
		return "won";
	}

private:

};

#endif // !PET_H

