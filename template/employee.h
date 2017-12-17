#ifndef employee_h
#define employee_h
#include <string>
#include <ostream>
using namespace std;

class Employee{
public:
       
  	string kto;
	string stanowisko;
	int wiek;

	Employee(string new_kto="brak danych", string new_stanowisko="brak danych", int new_wiek=0)
	{
		kto=new_kto;
		stanowisko=new_stanowisko;
		wiek=new_wiek;
	}

	~Employee() 
	{
	};

	friend ostream& operator << (ostream& o, const Employee& e)
	{
		return o << e.kto << ' ' << e.stanowisko << ' ' << e.wiek;
	}
};
#endif
