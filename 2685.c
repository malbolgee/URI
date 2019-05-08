/*
	@autor: Malbolge;
	@data: 07/05/2019;
	@nome: A Mudança;
*/

#include <stdio.h>

#define true 1
#define false 0

void main ()
{

	int i;

	while (scanf("%d", &i) != EOF)
	{

		if (i >= 0 && i < 90 || i == 360)
			printf("Bom Dia!!\n");
		else if (i >= 90 && i < 180)
			printf("Boa Tarde!!\n");
		else if (i >= 180 && i < 270)
			printf("Boa Noite!!\n");
		else if ( i >= 270 && i < 360)
			printf("De Madrugada!!\n");
			

	}
}