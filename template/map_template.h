# ifndef map_temlate_h
# define map_template_h
#include <ostream>
template <typename ID, typename dane>
class map_template
{
	struct lista
	{
		lista* next;
		ID idt;
		dane danet;
		lista(): next(NULL) { }
	};
	
	lista* first;
	
public:
	map_template(): first(NULL) { }
	map_template(const lista& m);
	


	void add(ID idd, dane dd)
	{
		lista* node=new lista;
		node->next=first;
		first=node;
		node->idt=idd;
		node->danet=dd;	
	}
	dane* find(ID idd)
	{
		for(lista* i=first; i!=NULL; i=i->next)
		{
			if(idd==i->idt)
			{
				return &(i->danet);
			}
		}
		return 0;
		//return &((lista* l=new lista)->danet);
	}
	/*void remove(ID idd)
	{
		for(lista* i=first; i!=NULL;)
		{
			if(idd==i->idt)

		i=i->next;
		}
	}*/
	~map_template() 
	{ 
		for(lista* i=first, *n = (first ? first->next : 0);i!=NULL; i=n,n=(n ? n->next : 0))
		{
			delete i;
        }
	}
	friend std::ostream& operator << (std::ostream& o, const map_template& m)
	{
		for (lista* i = m.first; i; i = i->next)
			o << i->idt << ": " << i->danet << '\n';
		return o;
	}
};

/*template<typename ID,typename dane> dane map_template<ID,dane>::find(ID idx)
{
	for(int i=)
}*/

/*template<typename ID, typename dane> void map_template<ID,dane>::add(ID idd,dane dd)
{
		lista* node=new lista;
		node->next=first;
		first=node;
		node->idt=m.idd;
		node->danet=m.dd
}*/

# endif /* map_template.h */
