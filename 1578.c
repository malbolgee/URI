/*
	@autor: Malbolge;
	@data: 02/10/2018;
	@nome: Matriz de Quadrados;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned short casos, qtsCaso = 4, ordem;
	unsigned short linha, coluna, qtsDigitosAtual, k;
	long double maior;

	scanf("%hu", &casos);
	while (casos--)
	{

		scanf("%hu", &ordem);

		long double matriz[ordem][ordem];

		// Preenche a matriz e já faz o quadrado do termo;
		for (linha = 0; linha < ordem; linha++)
			for (coluna = 0; coluna < ordem; coluna++)
			{
				scanf("%Lf", &matriz[linha][coluna]);
				matriz[linha][coluna] *= matriz[linha][coluna];
			}

		printf("Quadrado da matriz #%hu:\n", qtsCaso);
		for (linha = 0; linha < ordem; linha++)
		{	
			
			for (coluna = 0; coluna < ordem; coluna++)
			{
				maior = 0;
				
				// Acha o maior elemento da coluna;
				for (k = 0; k < ordem; k++)
					if (matriz[k][coluna] > maior)
						maior = matriz[k][coluna];

				// O recuo no printf é em termos do maior elemento da coluna;
				// Ou seja, todos os elementos da coluna estão justificados
				// de acordo com o número que tem a maior quantidade de dígitos
				// nessa mesma coluna;

				// log na base 10 nos da a quantidade de digitos de um número;
				qtsDigitosAtual = ((floor(log10(maior))) + 1);
				
				// flag '*' antes da diretiva de formatação nos dá um recuo dinâmico
				// Na impressão;

				// Tive muitos problermas por causa disso;
				// Não pode haver espaços após o último elemento na coluna!
				if (coluna != ordem && coluna != 0)
					printf(" ");

				printf("%*.Lf", qtsDigitosAtual, matriz[linha][coluna]);
			}


			printf("\n");

		}

		qtsCaso++;

		// Quebra de linha condicional para não imprimir caso seja a última matriz;
		if (casos != 0)
			printf("\n");
	}

}