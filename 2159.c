/*
	@autor: Malbolge;
	@data: 23/12/2018;
	@nome: Número Aproximado de Primos;
*/

#include <stdio.h>
#include <math.h>

#define CONSTANTE 1.25506

void main ()
{

	unsigned numero;
	scanf("%u", &numero);

	printf("%.1f ", (numero / log(numero)));
	printf("%.1f\n", ((CONSTANTE * numero) / log(numero)));

}
