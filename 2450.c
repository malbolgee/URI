/*
	@autor: Malbolge;
	@data: 09/01/2019;
	@nome: Matriz Escada;
*/

#include <stdio.h>

#define true 1
#define false 0

void main ()
{

	int ppp = 0;
	int c, qtsZeros;
	int linha, coluna;
	_Bool bo, ok = true;
	int qtsLinha, qtsColuna;

	scanf("%d %d", &qtsLinha, &qtsColuna);

	for (linha = 0; linha < qtsLinha; ++linha)
	{

		qtsZeros = 0;
		bo = true;

		for (coluna = 0; coluna < qtsColuna; ++coluna)
		{

			scanf("%d", &c);
			if (c == 0 && bo)
				qtsZeros++;
			else
				bo = false;

		}

		if (linha != 0)
		{

			if ((qtsZeros > ppp || (qtsZeros == ppp && qtsZeros == qtsColuna)) && ok)
				ppp = qtsZeros;
			else
				ppp = 0, ok = false;

		}
		else
			ppp = qtsZeros;

	}

	if (ppp)
		printf("S\n");
	else
		printf("N\n");

}
