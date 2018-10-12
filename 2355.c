/*
	@autor: Malbolge;
	@data: 12/10/2018;
	@nome: Brasil e Alemanha;
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void main ()
{

	double minutos, feitosBrasil, feitosAlemanha;

	while (true)
	{

		scanf("%lf", &minutos);

		if (minutos == 0)
			break;

		feitosBrasil = floor(minutos / 90);
		feitosAlemanha = ceil(7 * minutos / 90);

		printf("Brasil %.lf x Alemanha %.lf\n", feitosBrasil, feitosAlemanha);

	}
}
