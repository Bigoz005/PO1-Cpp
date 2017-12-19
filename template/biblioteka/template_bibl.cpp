# include "biblioteka.h"
# include "map_template2.h"
# include <iostream>

using namespace std;

int main()
{
	try{
	typedef string ID;
	map_template<ID,Biblioteka> Database;
	Database.add("Bajki Brzechwy",Biblioteka("Jan Brzechwa","Bajki Brzechwy","Na stanie",58));
	Database.add("Pan Tadeusz",Biblioteka("Adam Mickiewicz","Pan Tadeusz","Wypozyczone",765));
	Database.add("Symfonia C++ Standard",Biblioteka("Jerzy Grębosz","Symfonia C++ Standard","Wypozyczone",1354));
	cout << Database << endl;

	map_template<ID,Biblioteka> NewDatabase = Database;

	Biblioteka* pB;
	pB = NewDatabase.find("Pan Tadeusz");
	pB->lstron = 813;
	pB = NewDatabase.find("Bajki Brzechwy");
	pB->status = "Wypozyczone";
	pB = NewDatabase.find("Symfonia C++ Standard");
	pB->status = "Na stanie";
	
	Database = NewDatabase;
	cout << Database << endl;
	}

	catch(...)
	{
		cout << "error" << endl;
	}

    return 0;
}
