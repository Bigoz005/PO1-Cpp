#include <stdio.h>
#include "stack.h"

int main()
{
	int dane;
	printf("podaj rozmiar :");
	scanf("%d", &d);
	*dane = (int*) malloc (sizeof(int)*n);
	stack s1;
	stack s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(5);
	s2.push(6);
	printf("%d %d\n",s1.pop(),s2.pop());
	printf("%d\n",s1.pop());
	free(s1.dane);
	free(s2.dane);
	return 0;
}
