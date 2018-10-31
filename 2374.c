/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Pneu;
*/

#include <stdio.h>

void main ()
{

	short pressaoDesejada, pressaoLida;

	scanf("%hd %hd", &pressaoDesejada, &pressaoLida);

	printf("%hd\n", pressaoDesejada - pressaoLida);


}
