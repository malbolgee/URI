/*
	@autor: Malbolge;
	@data: 10/08/2018;
	@nome: Guilherme e Suas Pipas;
*/

#include <stdio.h>

int main ()
{

	long long int lados, resultado;

	scanf("%lld", &lados);
	resultado = ((lados - 3)* lados) /2;

	printf("%lld\n", resultado);

}
