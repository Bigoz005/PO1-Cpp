#include <assert.h>
#include <stdlib.h>
#include "stack.h" 



//using namespace std;

stack::stack()
{
	this->top=0;
	size = 0;
	dane = NULL;
	dane = (int*)malloc(sizeof(int));
	

}

stack::~stack()
{
         free(dane);
         top=0;
        //cout<<"sdas";
}

void stack::clear()
{
	this->top=0;
}

void stack::push(int n)
{


	if (top>=size) {
	
		
		int* newDane = (int*)realloc(dane,size++*sizeof(int));
		//dane = (int*)realloc(dane, sizeof(dane) * newSize);
		if (newDane) {
			dane=newDane;
		} else {
			free(dane);
			exit(1);
		}
		
		
		
	}
	dane[top++] = n;
	
	
}

int stack::pop()
{
	assert(top>0);
	return dane[--top];
}


