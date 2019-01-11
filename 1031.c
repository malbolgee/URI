/*
	@autor: Malbolge;
	@data: 11/01/2019;
	@nome: Crise de Energia;
*/

#include <stdio.h>

#define true 1
#define false 0

int josephus(int n, int k);

void main ()
{

	int qtsRegioes, pulo;

	while (true)
	{

		scanf("%d", &qtsRegioes);
		if (qtsRegioes == 0)
			break;

		pulo = 1;
		while (true)
		{

			if (josephus(qtsRegioes, pulo) != 11)
				pulo++;
			else
				break;

		}

		printf("%d\n", pulo);

	}


}

int josephus(int n, int k)
{

	int i;
	int retorno = 0;

	for (i = 1; i < n; ++i)
		retorno = (retorno + k) % i;

	return retorno;

}
