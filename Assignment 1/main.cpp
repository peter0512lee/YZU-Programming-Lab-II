//��J���B�e�A��X���n�P�P���A�æL�X�ϧ�
#include<iostream>
#include"Rectangle.h"
using namespace std;

int main() 
{
	int length;
	int width;
	char ch;
	Rectangle rect;
	cout << "length: ";
	cin >> length;
	cout << "width: ";
	cin >> width;
	rect.setLength(length);
	rect.setWidth(width);
	cout << "FillCharacter: ";
	cin >> ch;
	rect.setFillCharacter(ch);
	cout << "Perimeter: ";
	cout << rect.getPerimeter() << endl;
	cout << "Area: ";
	cout << rect.getArea() << endl;
	rect.draw();

	system("pause");
}

