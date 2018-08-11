/*
  @autor: Malbolge;
  @data: 06/08/2018;
  @nome: Área Inferior;
*/

#include <stdio.h>

int main ()
{

	double m[12][12], soma = 0, media = 0;
	char operacao;
	unsigned short i, j, cont = 0;

	scanf("%c", &operacao);

	for(i = 0; i < 12; i++)
		for(j = 0; j < 12; j++)
			scanf("%lf", &m[i][j]);

	if (operacao == 'S')
	{

		for(i = 0; i < 12; i++)
			for(j = 0; j < 12; j++)
				if (i > j && i > 12 - j - 1)
					soma += m[i][j];

		printf("%.1lf\n", soma);
	}

	if (operacao == 'M')
	{

		for(i = 0; i < 12; i++)
			for(j = 0; j < 12; j++)
				if (i > j && i > 12 - j - 1)
				{
					media += m[i][j];
					cont++;
				}

		printf("%.1lf\n", media/cont);
	}
}
