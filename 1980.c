/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: Embaralhando;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	char string[20];
	unsigned long long fatorial = 1;
	unsigned short i, contador = 0, tamanho;

	while (1)
	{
		scanf("%s", string);

		if (string[0] == '0')
			break;

		tamanho = strlen(string);

		while (tamanho)
		{

			fatorial *= tamanho--;

		}

		printf("%llu\n", fatorial);
		fatorial = 1;
		
	}
}