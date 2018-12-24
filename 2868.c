/*
	@autor: Malbolge;
	@data: 24/12/2018;
	@nome: Errrou!;
*/

#include <stdio.h>
#include <stdlib.h>

void main ()
{

	unsigned short casos, i;
	char operacao, string[1000];
	int numeroA, numeroB, resposta, respostaDada;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%d %c %d = %d", &numeroA, &operacao, &numeroB, &respostaDada);

		if (operacao == '+')
			resposta = numeroA + numeroB;
		else if (operacao == '-')
			resposta = numeroA - numeroB;
		else if (operacao == 'x')
			resposta = numeroA * numeroB;

		i = 1;

		resposta = abs(respostaDada - resposta);

		string[0] = 'E';
		while (i <= resposta)
			string[i++] = 'r';

		string[i++] = 'o';
		string[i++] = 'u';
		string[i++] = '!';
		string[i] = '\0';

		printf("%s\n", string);

	}

}
