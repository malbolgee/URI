#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned short casos, qtsCaso = 4, ordem;
	unsigned short linha, coluna, qtsDigitos2;
	double maior, qtsDigitos, aux;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &ordem);

		unsigned int matriz[ordem][ordem];

		maior = 0;
		for (linha = 0; linha < ordem; linha++)
			for (coluna = 0; coluna < ordem; coluna++)
				scanf("%d", &matriz[linha][coluna]);

		for (linha = 0; linha < ordem; linha++)
			for (coluna = 0; coluna < ordem; coluna++)
				matriz[linha][coluna] *= matriz[linha][coluna];

		for (linha = 0; linha < ordem; linha++)
			for (coluna = 0; coluna < ordem; coluna++)
				if (matriz[linha][coluna] > maior)
					maior = matriz[linha][coluna];

		qtsDigitos = 0;
		while (maior)
		{

			maior = maior / 10;
			qtsDigitos++;

		}

		
		printf("Quadrado da matriz #%hu:\n", qtsCaso);
		for (linha = 0; linha < ordem; linha++)
		{	
			
			for (coluna = 0; coluna < ordem; coluna++)
			{

				aux = matriz[linha][coluna];
				qtsDigitos2 = 0;	
				while (aux)
				{

					aux = aux / 10;
					qtsDigitos2++;

				}

				qtsDigitos2 = qtsDigitos2 - qtsDigitos;

				printf("%*.Lf ", qtsDigitos, matriz[linha][coluna]);
			}

			printf("\n");

		}

		qtsCaso++;

		printf("\n");
	}

}