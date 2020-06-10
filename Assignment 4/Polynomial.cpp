#include<iostream>
#include<vector>
using namespace std;
#include"Polynomial.h"

Polynomial::Polynomial(int expNum) {
	terms.resize(expNum);
}

ostream& operator<<(ostream &out, const Polynomial &outPolynomial) {

	for (int i = 0; i < outPolynomial.terms.size(); i++) {
		if (outPolynomial.terms.size() - 1 > i)
			out << outPolynomial.terms[i] << " * X^" << i << " + ";
		else
			out << outPolynomial.terms[i] << " * X^" << i << "\n";
	}
	cout << endl;
	return out;

}

istream& operator>>(istream &in, Polynomial &outPolynomial) {
	
	for (int i = 0; i < outPolynomial.terms.size(); i++)
		in >> outPolynomial.terms[i];

	return in;
}

Polynomial::Polynomial(Polynomial &rightPolynomial) {

	terms.resize(rightPolynomial.terms.size());
	for (int i = 0; i < rightPolynomial.terms.size(); i++)
		terms[i] = rightPolynomial.terms[i];
	
}

Polynomial Polynomial::operator+(Polynomial &rightPolynomial) {
		
	Polynomial m(*this);//m = p
	for (int i = 0; i < rightPolynomial.terms.size(); i++)
		m.terms[i] += rightPolynomial.terms[i];

	return m;
}

Polynomial Polynomial::operator-(Polynomial &rightPolynomial) {	Polynomial n(*this);

	for (int i = 0; i < rightPolynomial.terms.size(); i++)
		n.terms[i] -= rightPolynomial.terms[i];

	return n;}Polynomial Polynomial::operator=(Polynomial &rightPolynomial) {
	terms.resize(rightPolynomial.terms.size());
	for (int i = 0; i < rightPolynomial.terms.size(); i++)
		terms[i] = rightPolynomial.terms[i];	return *this;}