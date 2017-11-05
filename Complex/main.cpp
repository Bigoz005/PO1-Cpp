#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex a(4);
	Complex b(5,7);
	cout << "Modul liczby zespolonej b = " << b.modul() << endl;
	a=b;
	a+b;
	Complex c(2,2);
	a*c;
	return 0;
}
