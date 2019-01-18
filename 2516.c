/*
	@autor: Malbolge;
	@data: 18/01/2019;
	@nome: Corrida;
*/

#include <stdio.h>

void main ()
{

	double s, va, vb;

	while (scanf("%lf %lf %lf", &s, &va, &vb) != EOF)
		if (va <= vb)
			printf("impossivel\n");
		else
		{

			double tempo = s / (va - vb) * 1.0f;
			printf("%.2lf\n", tempo);

		}

}
