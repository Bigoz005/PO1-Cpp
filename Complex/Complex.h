#ifndef COMPLEX_H_INCLUDED
	#define COMPLEX_H_INCLUDED
	#include <iostream>
	#include <math.h>

	using namespace std;

	class Complex {
	private:
		double Re;
		double Im;
	public:
		Complex() {
			Re = 0;
			Im = 0;
		}
		Complex(double newRe) {
			Re = newRe;
			Im = 0;
			cout << "Stworzono nowy obiekt re=" << this->Re << " im=" << this->Im << endl;
		}

		Complex(double newRe, double newIm) {
			this->Re = newRe;
			this->Im = newIm;
			cout << "Stworzono nowy obiekt re=" << this->Re << " im=" << this->Im << endl;
		}

		Complex operator=(const Complex& co) {
			this->Re = co.Re;
			this->Im = co.Im;
			cout << "Przypisano do obiektu wartosci. a.Re=" << this->Re << " a.Im=" << this->Im << endl;
		}
		Complex operator+(const Complex& co) const {
			Complex x;
			x.Re = this->Re+co.Re;
			x.Im = this->Im+co.Im;
			cout << "Nowe wartosci: Re=" << x.Re << " Im=" << x.Im << endl;
			return x;
		}
		Complex operator-(const Complex& co) const {
			Complex x;
			x.Re = this->Re - co.Re;
			x.Im = this->Im - co.Im;
			return x;
		}
		Complex operator* (const Complex& co) const {
			Complex x;
			x.Re = (this->Re * co.Re)-(this->Im * co.Im);
			x.Im = (this->Im * co.Re)+(this->Re * co.Im);
			cout << "Nowe wartosci: x.Re=" << x.Re << " x.Im=" << x.Im << endl;
			return x;
		}
		double modul() {
			return (sqrt(pow(this->Re, 2)+pow(this->Im, 2)));
		}
	};


#endif
