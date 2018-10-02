/*
	@autor: Malbolge;
	@data: 01/10/2018;
	@nome: CPF 2;
*/

#include <stdio.h>
#include <string.h>

void makeInt(char *str, short vet[]);

void main ()
{

	char cpf[10];
	short numCPF[9];
	unsigned short digitoA, digitoB;
	unsigned i, j, k;

	while (scanf(" %s", cpf) != EOF)
	{

		makeInt(cpf, numCPF);

		digitoA = 0;
		digitoB = 0;

		for (i = 0, j = 1, k = 9; i < 9; i++, j++, k--)
			{	
				digitoA += numCPF[i] * j;
				digitoB += numCPF[i] * k;
			}

			digitoA = digitoA % 11;
			if (digitoA == 10)
				digitoA = 0;

			digitoB = digitoB % 11;
			if (digitoB  == 10)
				digitoB = 0;

			for (i = 0; i < 3; i++)
				printf("%hu", cpf[i] - 48);

			printf(".");

			for (i = 3; i < 6; i++)
				printf("%hu", cpf[i] - 48);

			printf(".");

			for (i = 6; i < 9; i++)
				printf("%hu", cpf[i] - 48);

			printf("-");

			printf("%hu%hu", digitoA, digitoB);

			printf("\n");

	}
}

void makeInt(char *str, short vet[])
{

	unsigned short i;

	for (i = 0; i < 9; i++)
		vet[i] = (int)str[i] - 48;

}
