/*
	@autor: Malbolge;
	@data: 19/09/2018
	@nome: Números de Ahmoc;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main ()
{

	char painel[300001], assinatura[10];
	unsigned instancias = 1;

	while (true)
	{
		scanf("%s", assinatura);

		if (strcmp(assinatura, "0") == 0)
			break;
		if (instancias != 1)
			printf("\n");

		scanf(" %s", painel);

		if (strstr(painel, assinatura))
		{
			printf("Instancia %u\n", instancias);
			printf("verdadeira\n");
		}
		else
		{
			printf("Instancia %u\n", instancias);
			printf("falsa\n");

		}

		instancias++;

	}

}