/*
	@autor: Malbolge;
	@data: 08/01/2019;
	@nome: Colocando Radares;
*/

#include <stdio.h>
#include <math.h>

void main ()
{
	unsigned n;
	float a, b;

	scanf("%u", &n);

	while (n--)
	{

		scanf("%f %f", &a, &b);

		printf("%.f\n", ceil(a / b));

	}

}
