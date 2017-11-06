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

		Complex() {
			Re = 0;
			Im = 0;
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
		Complex operator/(const Complex& co) const {
			Complex x;
    			double w;
     			w = co.Re * co.Re + co.Im * co.Im;
				if(w>0){
        				x.Re = (this->Re * co.Re + this->Im * co.Im)/w;
        				x.Im = (co.Re * this->Im - this->Re * co.Im)/w;
					cout << "Nowe wartosci: x.Re = " << x.Re << " x.Im = " << x.Im << endl;
		 		return x;
      				}
     				else{
        				cout << "Blad podczas dzielenia!" << endl;
        			return 0;
      				}
		}

		Complex operator/=(const Complex& co) {
			Complex x;
      			double w;
      			w = co.Re * co.Re + co.Im * co.Im;
				if(w>0){
        				x.Re = (this->Re * co.Re + this->Im * co.Im)/w;
				        x.Im = (co.Re * this->Im - this->Re * co.Im)/w;
      				}
			        else{
				        cout << "Blad podczas dzielenia!" << endl;
			        return 0;
      				}
	 		this->Re = x.Re;
			this->Im = x.Im;
			cout << "Przypisano do obiektu wartosci. x.Re = " << this->Re << " x.Im = " << this->Im << endl;
			cout << "Nowe wartosci: x.Re = " << x.Re << " x.Im = " << x.Im << endl;
		return x;
		}
		
		double abs() {
			return (sqrt(pow(this->Re, 2)+pow(this->Im, 2)));
		}
		Complex phase() {
		//faza liczby zespolonej	
		}
	
		Complex conj(){
     	 		Complex Conj;
     			Conj.Im = -1 * Im;
	      		Conj.Re = Re;
		return Conj;
    		}
	};

#endif
