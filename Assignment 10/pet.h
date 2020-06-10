#pragma once
#ifndef PET_H
#define PET_H
#include<iostream>
#include<string>
using namespace std;

class petImp;

class pet
{
public:
	pet(string s);	
	string Name();
	virtual string makeSound();

protected:
	petImp * impl;
};

class cat : public pet
{
public:
	cat(string s);		
};

class dog : public pet
{
public:
	dog(string s);		
};

#endif // !PET_H

