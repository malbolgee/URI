/*
	@autor: Malbolge;
	@data: 15/10/2018;
	@nome: Pentágono;
*/

#include <stdio.h>
#include <math.h>
#define TORTA 3.14159265358979323846

void main ()
{
	unsigned casos;
	long double comprimentoLado;
	long double altura, area;

	scanf("%u", &casos);

	while (casos--)
	{

		scanf("%Lf", &comprimentoLado);

		altura = comprimentoLado / (2.00f * tan((36 * TORTA) / 180.0f));

		area = (10 * ((comprimentoLado * altura) / 4.00f));

		printf("%.3Lf\n", area);

	}

}
