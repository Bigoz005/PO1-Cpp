# include "employee.h"
# include "map_template2.h"
# include <iostream>

using namespace std;

int main()
{
	try{
	typedef unsigned int ID;
	map_template<ID,Employee> Database;
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
		cout << "error" << endl;
	}
	
    return 0;
}

