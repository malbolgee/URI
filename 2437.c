/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Distância de Manhattan;
*/

#include <stdio.h>
#include <stdlib.h>

void main ()
{

	unsigned short xMaria, yMaria;
	unsigned short xReuniao, yReuniao;

	scanf("%hu %hu %hu %hu", &xMaria, &yMaria, &xReuniao, &yReuniao);

	printf("%hu\n", abs(xReuniao - xMaria) + abs(yReuniao - yMaria));


}
