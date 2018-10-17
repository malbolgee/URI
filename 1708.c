/*
	@autor: Malbolge;
	@data: 17/10/2018;
	@nome: Volta;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	float maisLento, maisRapido;
	float qtsVoltas;

	scanf("%f %f", &maisLento, &maisRapido);

	qtsVoltas = maisRapido - maisLento;
	qtsVoltas = maisRapido / qtsVoltas;

	printf("%.f\n", ceil(qtsVoltas));


}
