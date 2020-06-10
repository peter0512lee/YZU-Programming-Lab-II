#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace std;

class Rectangle  {

	public:		
		void setLength(int l = 1);
		int getLength();
		void setWidth(int w = 1);
		int getWidth();
		void draw();
		void setFillCharacter(char ch);
		int getPerimeter();
		int getArea();

	private:
		int length;
		int width;
		int perimeter;
		int area;
		char FillCharacter;

};

#endif 

