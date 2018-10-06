/*
	@autor: Malbolge;
	@data: 05/10/2018;
	@nome: Triangulação de Delaunay;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	double resultado;
	double numero, variavel;

	while (true)
	{

		scanf("%lf", &numero);

		if (numero == 0)
			break;

		variavel = numero + (numero - 3.0);

		printf("%lf\n", (variavel - numero) / (numero));


	}
}
