# include "employee.h" //defines class Employee
# include "map_template2.h" //defines template map_template<Key,Value>
# include <iostream>

using namespace std;

int main()
{
	try{
	typedef unsigned int ID; //Identification number of Employee
	map_template<ID,Employee> Database; //Database of employees
	Database.add(761028073,Employee("Jan Kowalski","salesman",28));
	Database.add(510212881,Employee("Adam Nowak","storekeeper",54));
	Database.add(730505129,Employee("Anna Zaradna","secretary",32));
	cout << Database << endl;
	
	map_template<ID,Employee> NewDatabase = Database;
	
	Employee* pE;
	pE = NewDatabase.find(510212881);
	pE->stanowisko = "salesman";
	pE = NewDatabase.find(761028073);
	pE->wiek = 29;
	
	Database = NewDatabase;
	cout << Database << endl;
	
	
	
	}
	catch(...)
	{
		cout << "blad!!!" << endl;
	}
	

    	
    return 0;
}

