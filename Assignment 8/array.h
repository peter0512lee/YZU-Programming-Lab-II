// The example of C++ Class
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

using namespace std;

template<typename T>
class Array {
    public:
        Array(int s);
        ~Array();
        void setValue(int index, T value);
        T getValue(int index);
    private:
        int Size;
        T *ArrayPtr;
};

template<typename T>
Array<T>::Array(int s) :Size(s), ArrayPtr((s > 0) ? new T[s]() : nullptr) {
}

template<typename T>
Array<T>::~Array() {
	if (ArrayPtr != nullptr)
		delete[] ArrayPtr;
}

template<typename T>
void Array<T>::setValue(int index, T value) {
	ArrayPtr[index] = value;
}

template<typename T>
T Array<T>::getValue(int index) {
	return ArrayPtr[index];
}

#endif // ARRAY_H
