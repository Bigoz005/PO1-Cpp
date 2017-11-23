#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex a(4);
	Complex b(5,7);
	a=b;
	a+b;
	Complex c(2,2);
    a.operator*(c);
	a/b;
    a/=b;
    b-4;
    5-a;
    cout << "Modul liczby zespolonej b = " << b.abs() << endl;
    cout<< "Conj: "<<b.conj()<<"\n";
    cout << "Faza: " << b.phase()<<"\n";

    const Complex r = b;
    cout << "Faza: " << r.phase()<<"\n";

	return 0;
}
