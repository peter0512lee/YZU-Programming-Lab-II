#include<iostream>
#include"Rectangle.h"
using namespace std;


void Rectangle::setLength(int l) {

	length = l;
	if (length < 2)
		length = 2;
	if (length > 20)
		length = 20;
}

int Rectangle::getLength() {

	return length;
}

void Rectangle::setWidth(int w) {

	width = w;
	if (width < 2)
		width = 2;
	if (width > 20)
		width = 20;
}

int Rectangle::getWidth() {

	return width;
}

void Rectangle::draw() {

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || i == length - 1 || j == 0 || j == width - 1)
				cout << FillCharacter;
			else
				cout << " ";
		}
		cout << endl;
	}


		
}

void Rectangle::setFillCharacter(char ch) {

	FillCharacter = ch;
}

int Rectangle::getPerimeter() {

	return (length + width) * 2;

}

int Rectangle::getArea() {

	return length * width;

}