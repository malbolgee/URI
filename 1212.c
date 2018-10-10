/*
	@autor: Malbolge;
	@data: 09/10/2018;
	@nome: Aritmética Primária;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned valorA, valorB, carregador, vaium;

	while (true)
	{

		scanf("%u %u", &valorA, &valorB);

		if (valorA == 0 && valorB == 0)
			break;

		vaium = 0;
		carregador = 0;
		while (valorA || valorB)
		{
			// Se a soma dos últimos algarismos dos números der um valor maior do que 9
			// Será preciso "subir 1";
			// Variável 'carregador' incrementa em 1 para contabilizar quantas vezes
			// Esse 'vaium' foi utilizado
			// E a variável 'vaium' recebe o valor de 1 para a próxima iteração;
			if (((valorA % 10) + (valorB % 10) + vaium) > 9)
			{
				carregador++;
				vaium = 1;
			}
			else
				vaium = 0;

			// Passa para o próximo digito;
			valorA /= 10;
			valorB /= 10;

		}


		if (carregador == 0)
			printf("No carry operation.\n");
		else if (carregador == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", carregador);


	}
}
