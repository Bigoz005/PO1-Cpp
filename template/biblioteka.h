#ifndef biblioteka_h
#define biblioteka_h
#include <string>
#include <ostream>
using namespace std;

class Biblioteka{
public:
       
  	string autor;
	string kategoria;
	string status;
	int lstron;

	Biblioteka(string new_autor="Nie podano", string new_kategoria="Nie podano", string new_status="Nie podano", int new_lstron=0)
	{
		autor=new_autor;
		kategoria=new_kategoria;
		status=new_status;
		lstron=new_lstron;
	}

	~Biblioteka()
	{
	};

	friend ostream& operator << (ostream& o, const Biblioteka& e)
	{
           return o << e.autor << ' ' << e.kategoria << ' ' << e.status << ' ' << e.lstron;
	}
};
#endif
