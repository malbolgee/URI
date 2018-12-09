/*
	@autor: Malbolge;
	@data: 08/12/2018;
	@nome: Batmain;
*/

#include <stdio.h>

void main ()
{

	unsigned short qtsBandidos;
	unsigned short i;
	char bandido[100];

	scanf("%hu", &qtsBandidos);

	for (i = 0; i < qtsBandidos; i++)
	{

		scanf(" %[^\n]", bandido);
		printf("Y\n");

	}

}
