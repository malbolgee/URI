/*
	@autor: Malbolge;
	@data: 06/10/2018;
	@nome: Viagem à Marte na Velocidade de Primo;
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool calcPrime(unsigned);

void main ()
{

	unsigned peso, velocidade = 0;
	unsigned short contador = 0;
	unsigned horas, dias;

	scanf("%u", &peso);

	while (contador < 10)
	{

		if (calcPrime(peso))
		{
			velocidade += peso;
			peso++;
			contador++;
		}
		else
			peso++;

	}

	horas = (60000000 / velocidade);
	dias = (horas / 24);

	printf("%u km/h\n", velocidade);
	printf("%u h / %u d\n", horas,  dias);

}


bool calcPrime(unsigned numero)
{

	unsigned i;
	unsigned limite;

	limite = sqrt(numero);

	if (numero % 2 == 0 && numero != 2 || numero == 1)
		return false;

	for (i = 3; i <= limite; i++)
		if (numero % i == 0)
			return false;

	return true;

}
