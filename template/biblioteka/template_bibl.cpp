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
	cout << Database << endl;

	map_template<ID,Biblioteka> NewDatabase = Database;

	Biblioteka* pE;
	pE = NewDatabase.find("Pan Tadeusz");
	pE->lstron = 813;
	pE = NewDatabase.find("Bajki Brzechwy");
	pE->status = "Wypozyczone";

	Database = NewDatabase;
	cout << Database << endl;
	}

	catch(...)
	{
		cout << "error" << endl;
	}

    return 0;
}
