template <typename key, typename data>

class map_template
{
	private:
		struct node
		{
			key klucz;
			data dane;
			node* next;
			
			node(): next(NULL)
			{
			}
		};
	
	node* head;
	
	public:
		
		map_template(): head(NULL) //konstruktor z lista inicjalizacyjna zeby nie pisac w ciele konstruktora ze head to null
		{
		}
	
		map_template (const map_template & z)
		{
			node * pa = 0; //aktualny węzeł
			node * pn = 0; //nastepny węzeł
			try{
				if( z.head == 0 )
				{
					head = 0;
				}	
				else
				{
					head = new node;
					head -> klucz = z.head -> klucz;
					head -> dane = z.head -> dane;

					pa = head;
					pn = z.head -> next;
				}
				while( pn )
				{
					pa -> next = new node;
					pa = pa -> next;
					pa -> klucz = pn -> klucz;
					pa -> dane = pn -> dane;
					pn = pn -> next;
				}
				pa -> next = 0;
			}
			catch (...)
			{
				while (head)
				{
					node *t = head->next;
					delete head;
					head = t;
				};
				
			throw;
			};
		}
	
		map_template& operator= (const map_template & l)
		{
			if (&l == this) 		
			{
				return *this;
			}
		
			map_template t (l);
		
			node *k = head;
			head = t.head;
			t.head = k;
			
			return *this;
		}
	
		~map_template() //destruktor listy
		{
			while(head)
			{
				node* tmp = head;
				head = head -> next;
				delete tmp;
			}
		}
		
		void add(key klucz_nowy, data dane_nowy)
		{
			node* wezel = new node;
			try
			{
				wezel->klucz=klucz_nowy;
				wezel->dane=dane_nowy;
			}
			catch (...)
			{
				delete wezel;
				throw;
			};
			
			wezel->next=head;
			head=wezel;
		}
		
		data* find(key klucz_szukaj)
		{
			for(node* i=head; i!=NULL; i=i->next)
			{
				if(klucz_szukaj==i->klucz)
				{
					return &(i->dane);
				}
			}
		return 0;
		}
	
	friend std::ostream& operator << (std::ostream& o, const map_template& m)
	{
		for (node* i = m.head; i; i = i->next)
		{
			o << i->klucz << ": " << i->dane << '\n';
		}		
	return o;
		
	}
};
