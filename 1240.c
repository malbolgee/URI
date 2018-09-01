/*
	@autor: Malbolge;
	@data: 01/09/2018;
	@nome: Encaixa ou Não I;
*/

#include <stdio.h>
#include <string.h>

void main (void)
{

	unsigned casos;
	char numero1[11], numero2[11];
	short i, j, contador = 0, tamanhoNum2, tamanhoNum1;

	scanf("%u", &casos);

	while (casos)
	{

		scanf(" %s %s", numero1, numero2);
		tamanhoNum2 = strlen(numero2), tamanhoNum1 = strlen(numero1);

		for (i = tamanhoNum2 - 1, j = tamanhoNum1 - 1; i > -1; i--, j--)
			if (numero2[i] == numero1[j])
				contador++;

		if (contador == tamanhoNum2)
			printf("encaixa\n");
		else
			printf("nao encaixa\n");

		contador = 0;
		casos--;
	}
}