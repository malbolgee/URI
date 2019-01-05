/*
	@autor: Malbolge;
	@data: 05/01/2019;
	@nome: Copa;
*/

#include <stdio.h>

void main ()
{

	unsigned short mestreKung, mestreLu;

	scanf("%hu %hu", &mestreKung, &mestreLu);

	if ((mestreLu - 1) / 2 == (mestreKung - 1) / 2)
		printf("oitavas\n");
	else if ((mestreLu - 1) / 4 == (mestreKung - 1) / 4)
		printf("quartas\n");
	else if ((mestreLu - 1) / 8 == (mestreKung - 1) / 8)
		printf("semifinal\n");
	else
		printf("final\n");

}
