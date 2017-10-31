

class stack
{
public:

	void push(int a);
	int pop();
	void clear();
	bool isEmpty();
	stack();
	~stack();
private:
	int top;
	int *dane;
	int size;
};

