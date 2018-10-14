/*
	@autor: Malbolge;
	@data: 13/10/2018;
	@nome: Qual é a Altura?;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned short casos;
	short coeficienteA, coeficienteB, coeficienteC;
	short delta;
	float vertice;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hd %hd %hd", &coeficienteA, &coeficienteB, &coeficienteC);
		
		delta = (coeficienteB * coeficienteB) - (4 * coeficienteA * coeficienteC);

		vertice = -(delta /(4.0f * coeficienteA));

		printf("%.2f\n", vertice);

	}

}
