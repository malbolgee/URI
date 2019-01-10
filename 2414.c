/*
	@autor: Malbolge;
	@data: 09/01/2019;
	@nome: Desafio do Maior Número;
*/

#include <stdio.h>

#define true 1
#define false 0

int max(int, int);

void main ()
{

	int a, b = 0;

	while(true)
	{

		scanf("%d", &a);
		if (a == 0)
			break;

		b = max(b, a);

	}

	printf("%d\n", b);

}

int max(int a, int b)
{

	if (a > b)
		return a;
	else
		return b;

}
