/*
	@autor: Malbolge;
	@data: 04/12/2018;
	@nome: Descobrindo Senha;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct digito{

	float digito;
	unsigned short posicao;

} digito;

void ordena(digito *, unsigned short tam);

void main ()
{

	unsigned short qtsDigitos;
	unsigned short qtsCasos = 0;
	unsigned short i;
	digito senha[10];

	while (scanf("%hu", &qtsDigitos) != EOF)
	{


		for (i = 0; i < 10; i++)
		{

			scanf("%f", &senha[i].digito);
			senha[i].posicao = i;

		}

		ordena(senha, 10);

		printf("Caso %hu: ", ++qtsCasos);
		for (i = 0; i < qtsDigitos; i++)
			printf("%hu", senha[i].posicao);

		printf("\n");

		memset(senha, 0, sizeof(senha));

	}

}

void ordena(digito *senha, unsigned short tam)
{

	short i = 1, j;
	digito pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = senha[i];

		while(j >= 0 && senha[j].digito < pivo.digito)
		{

			senha[j + 1] = senha[j];
			j--;

		}

		senha[j + 1] = pivo;
		i++;

	}

}
