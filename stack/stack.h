class stack
{
public:
	void push(int a);
	int pop();
	void clear();
	bool isEmpty();
	stack();
	~stack();
	int *dane;
	int size;
private:
	int top;
	
};
