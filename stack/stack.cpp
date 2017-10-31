#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack::stack()
{
	this->top=0;
	size =1;
	dane =NULL;
	dane =(int*)malloc(sizeof(int));
	if(dane==NULL)
	{
	  assert(dane=NULL);
	}
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

void stack::push(int a)
{
  
}

int stack::pop()
{
	assert(this->top>0);
	return this->dane[--this->top];
}
