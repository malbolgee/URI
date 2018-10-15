/*
	@autor: Malbolge;
	@data: 15/10/2015;
	@nome: Juros do Projeto;
*/

#include <stdio.h>

void main ()
{

	long double investimento, retorno;
	long double jurus;
	unsigned casos = 0;

	while (scanf("%Lf %Lf", &investimento, &retorno) != EOF)
	{

		jurus = retorno - investimento;

		jurus = (jurus*100) / investimento;

		printf("Projeto %u:\nPercentual dos juros da aplicacao: %.2Lf %%\n", ++casos, jurus);
		printf("\n");

	}


}
