#include <assert.h>
#include <stdlib.h>
#include "stack.h" 

stack::stack()
{
	this->top=0;
	size = 0;
	dane = (int*)malloc(sizeof(int));
}

stack::~stack()
{
         free(dane);
         top=0;
}

void stack::clear()
{
	this->top=0;
}

void stack::push(int n)
{


	if (top>=size) {
		int* newDane = (int*)realloc(dane,(size+1)*sizeof(int));
		if (newDane) {
			dane=newDane;
			size++;
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