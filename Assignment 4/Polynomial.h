#include<vector>
#include<iostream>
using namespace std;
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {

	friend ostream& operator<<(ostream &out, const Polynomial &outPolynomial);
	friend istream& operator>>(istream &in, Polynomial &outPolynomial);

public:
	Polynomial(int);
	Polynomial(Polynomial&);
	Polynomial operator+(Polynomial &rightPolynomial);
	Polynomial operator-(Polynomial &rightPolynomial);	Polynomial operator=(Polynomial &rightPolynomial);

private:
	vector<int> terms;

};


#endif // 



