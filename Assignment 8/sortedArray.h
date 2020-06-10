//Ä~©ÓArray.h°µSort
#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include <iostream>
#include "array.h"
using namespace std;
template<typename T>
class SortedArray  : public Array<T>
{
public:
	SortedArray(int t);
	~SortedArray();
	bool isgreater(int left, int right);
	bool isgreater(float left, float right);
	bool isgreater(string left, string right);
	void addValue(T t);
private:
	int Size;

};

template<typename T>
SortedArray<T>::SortedArray(int s)
	:Array(s), Size(s)
{	
}

template<typename T>
SortedArray<T>::~SortedArray()
{
}

template<typename T>
bool SortedArray<T>::isgreater(int left, int right)
{
	if (left > right)
		return true;
	else
		return false;

}

template<typename T>
bool SortedArray<T>::isgreater(float left, float right)
{
	if (left > right)
		return true;
	else
		return false;

}

template<typename T>
bool SortedArray<T>::isgreater(string left, string right)
{
	if (left[0] < right[0] || right == "\0")
		return true;
	else
		return false;

}

template<typename T>
void SortedArray<T>::addValue(T t)
{
	for (int i = 0; i < Size; i++)
	{
		if (isgreater(t, getValue(i)))
		{
			for (int j = Size - 1; j > i; j--)
				setValue(j, getValue(j - 1));		
			setValue(i, t);
			break;
		}

	}
}

#endif // !SORTEDARRAY_H

