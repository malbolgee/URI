/*
	@autor: Malbolge;
	@data: 23/12/2018;
	@nome: Tri-du;
*/

#include <stdio.h>

void main ()
{

	unsigned short cartaA, cartaB;

	scanf("%hu %hu", &cartaA, &cartaB);

	if (cartaA == cartaB)
		printf("%hu\n", cartaA);
	else if (cartaA > cartaB)
		printf("%hu\n", cartaA);
	else
		printf("%hu\n", cartaB);


}
