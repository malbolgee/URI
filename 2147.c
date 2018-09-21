/*
	@autor: Malbolge:
	@data: 20/09/2018;
	@nome: Galopeira;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	unsigned short casos;
	char palavra[10001];
	float resultado = 0.01f;


	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s", palavra);

		printf("%.2f\n", strlen(palavra)*resultado);


	}

}