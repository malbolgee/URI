/*
	@autor: Malbolge;
	@data: 16/10/2018;
	@nome: Super Primos: Ativar!;
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool verificaPrimo(unsigned numero);
bool verificaSuperPrimo(unsigned numero);

void main ()
{

	unsigned numero;

	while (scanf("%u", &numero) != EOF)
	{


		if (verificaPrimo(numero))
			if (verificaSuperPrimo(numero))
				printf("Super\n");
			else
				printf("Primo\n");
		else
			printf("Nada\n");

	}

}

bool verificaPrimo(unsigned numero)
{

	unsigned i, limite;

	limite = sqrt(numero);

	if (numero % 2 == 0 && numero != 2 || numero == 1)
		return false;

	for (i = 3; i <= limite; i += 2)
		if (numero % i == 0)
			return false;

	return true;

}

bool verificaSuperPrimo(unsigned numero)
{

	unsigned i;

	while (numero)
	{

		if (!verificaPrimo(numero % 10))
			return false;

		numero /= 10;

	}

	return true;
}
