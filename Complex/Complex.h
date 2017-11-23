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
		Complex(double newRe = 0, double newIm = 0) {
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
		Complex operator- () const
		{
		    return Complex(-Re,-Im);
		}
		Complex & operator+= (Complex co)
		{
		    Re += co.Re;
		    Im += co.Im;
		    return *this;
		}

		Complex & operator-= (Complex co)
		{
		    Re -= co.Re;
		    Im -= co.Im;
		    return *this;
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
		

		double abs() const
		{
			return (sqrt(pow(this->Re, 2)+pow(this->Im, 2)));
		}

		double phase() const
		{
			if (Re > 0){
				return atan(Im / Re)*180/3.1415;}
			else
			{
				if(Re<0){
					return ((atan(Im / Re))*180/3.1415+180);}
				else
				{
					if (Im >0){
						return 90;}
					else{
						return 270;}
				} 
			}
						
		}

		/*Complex conj(){
     	 		Complex Conj;
     			Conj.Im = -1 * Im;
	      		Conj.Re = Re;
		return Conj;
    		}*/

		double conj() const 
		{
		this->Im=-Im;
		}
		
	
		friend Complex operator- (Complex, Complex);
		
	};
	inline Complex 
		operator - (Complex s1, Complex s2)
		{
		  Complex n (s1);
		  return n -= s2;
	};
#endif
