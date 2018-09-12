/*
	@autor: Malbolge;
	@data: 11/09/2018;
	@nome: Pepe, Já Tirei a Vela!;
*/

#include <stdio.h>

void main ()
{

	unsigned short casos, ocorrencia;
	unsigned short hora, minuto;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu %hu %hu", &hora, &minuto, &ocorrencia);

		if (ocorrencia == 1)
			printf("%02hu:%02hu - A porta abriu!\n", hora, minuto);
		else
			printf("%02hu:%02hu - A porta fechou!\n", hora, minuto);

	}


}