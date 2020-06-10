#include <cassert>
#include <iomanip>
#include "matrix.h"

Matrix::Matrix()
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLUMNS; j++)
    (*this)(i, j) = 0;
}
   
double& Matrix::operator()(int i, int j)
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}

double Matrix::operator()(int i, int j) const
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}
   
// need to complete this function
Matrix& Matrix::operator+=(const Matrix& right)
{
	for (int i = 0; i < (*this).ROWS; i++)
		for (int j = 0; j < (*this).COLUMNS; j++)
			(*this)(i, j) = (*this)(i, j) + right(i, j);
   return *this;
}

// need to complete this function
Matrix operator+(const Matrix& left, const Matrix& right)
{
   Matrix result;
   for (int i = 0; i < left.ROWS; i++)
	   for (int j = 0; j < left.COLUMNS; j++)
		   result(i, j) = left(i, j) + right(i, j);
   return result;
}
   
// need to complete this function
Matrix operator*(const Matrix& left, const Matrix& right)
{
   Matrix result;
   for (int i = 0; i < left.ROWS; i++)
	   for (int j = 0; j < left.COLUMNS; j++)
		   for (int k = 0; k < left.ROWS; k++)
				result(i, j) += left(i, k) * right(k, j);
   return result;
}
   
// need to complete this function
Matrix operator*(const Matrix& left, double right)
{
   Matrix result;
   for (int i = 0; i < left.ROWS; i++)
	   for (int j = 0; j < left.COLUMNS; j++)
		   result(i, j) = left(i, j) * right;
   return result;
}
   
// need to complete this function
Matrix operator*(double left, const Matrix& right)
{
   return right * left;
}

// need to complete this function
ostream& operator<<(ostream& left, const Matrix& right)
{
	for (int i = 0; i < right.ROWS; i++)
	{
		for (int j = 0; j < right.COLUMNS; j++)
			left << setw(3) << right(i, j);
		cout << endl;
	}
   return left;
}
