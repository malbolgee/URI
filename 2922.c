/*
	@autor: Malbolge;
	@data: 10/01/2019;
	@nome: Salas de Aula;
*/

#include <stdio.h>

void swap(int *a, int *b);

void main ()
{

	int a, b;

	while (scanf("%d %d", &a, &b) != EOF)
	{

		if (a > b)
			swap(&a, &b);

		if (a == b)
			printf("%d\n", b - a);
		else
			printf("%d\n", b - a - 1);

	}

}


void swap(int *a, int *b)
{

	int c;
	c = *a;
	*a = *b;
	*b = c;

}
