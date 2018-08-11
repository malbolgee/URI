/*
	@autor: Malbolge;
	@data: 10/08/2018;
	@nome: Conta;
*/

#include <stdio.h>

int main ()
{

	unsigned short int n, indice, soma = 0, numero;

	scanf("%hd", &n);
	while (n != 0)
	{
		soma = 0;

		scanf("%hd", &numero);

		for (indice = 0; indice < numero; indice++)
			if (indice % 2 == 0)
				soma++;
			else
				soma--;
		n--;
		printf("%d\n", soma);

	}
}
