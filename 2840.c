/*
	@autor: Malbolge;
	@data: 17/10/2018;
	@nome: Balão++;
*/

#include <stdio.h>
#include <math.h>

#define TORTA 3.1415

void main ()
{

	long long volume, raio;
	long long qtsBaloes, qtsGas;

	scanf("%lld %lld", &raio, &qtsGas);

	raio = raio * raio * raio;
	// Cálculo do volume da uma esfera;
	volume = (4.0f * (TORTA * raio)) / 3.0f;

	qtsBaloes = 0;
	// Enquanto a quatidade de gás não chegar a 0
	// Vou subtraindo o volume da esfera dessa quantidade;
	// Cada vez que subtraio o volume da esfera dessa quantidade
	// Um Balão pôde ser enchido completamente;
	while (qtsGas > 0)
	{

		qtsGas -= volume;
		qtsBaloes++;

	}

	printf("%lld\n", qtsBaloes - 1);

}
