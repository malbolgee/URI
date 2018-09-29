/*
	@autor: Malbolge;
	@data: 29/09/2018;
	@nome: Dígitos;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned numeroA, numeroB;
	unsigned short casos;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%u %u", &numeroA, &numeroB);

		// É possível obter-se uma estimativa de quantos dígitos há em um número
		// usando logarítmo na base 10;
		// log10(1) = 0
		// log10(10) = 1
		// lo10(100) = 2
		// log10(1000) = 3
		// O logarítmo é uma função estritamente crescente. Assim sendo
		// se arredondarmos para baixo o seu valor, teremos isso:
		// de 1 a 9: Resultado é 0;
		// de 10 a 99: Resultado é 1;
		// de 100 a 999: Resultado é 2;
		// ...
		// Se somarmos 1 a este valor, teremos o número de digitos na base 10
		// de um número.
		printf("%.f\n", (floor(log10(pow(numeroA, numeroB)))) + 1);

	}
}