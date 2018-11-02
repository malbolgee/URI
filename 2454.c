/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Flíper;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned short portaP, portaR;

	scanf("%hu %hu", &portaP, &portaR);

	if (portaP == true && portaR == true)
		printf("A\n");
	else if (portaP == true && portaR == false)
		printf("B\n");
	else if (portaP == false)
		printf("C\n");


}
