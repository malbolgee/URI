/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Basquete de Bobôs;
*/

#include <stdio.h>

void main ()
{

	unsigned short distancia;

	scanf("%hu", &distancia);

	if (distancia <= 800)
		printf("1\n");
	else if (distancia <= 1400)
		printf("2\n");
	else
		printf("3\n");

}
