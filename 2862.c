/*
	@autor: Malbolge;
	@data: 14/10/2018;
	@nome: Inseto!;
*/

#include <stdio.h>

void main ()
{

	unsigned short casos;
	unsigned ki;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%u", &ki);

		if (ki > 8000)
			printf("Mais de 8000!\n");
		else
			printf("Inseto!\n");

	}

}
