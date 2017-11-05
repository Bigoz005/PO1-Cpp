#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double newRe) {
	Re = newRe;
	Im = 0;
	cout << "Stworzono nowy obiekt re=" << this->Re << " im=" << this->Im << endl;
}

Complex::Complex(double newRe, double newIm) {
	this->Re = newRe;
	this->Im = newIm;
	cout << "Stworzono nowy obiekt re=" << this->Re << " im=" << this->Im << endl;
}

Complex::Complex operator=(const Complex& s) {
	this->Re = s.Re;
	this->Im = s.Im;
}
