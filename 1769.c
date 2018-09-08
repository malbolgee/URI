/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: CPF 1;
*/

#include <stdio.h>
#include <ctype.h>

void transformaInt(char *, short vet[]);
void retiraPonto(char *, char *);

void main ()
{

	char cpf[15], cpfCpy[15];
	short numCPF[15], numB1 = 0, numB2 = 0;
	unsigned char numero, i = 0, j , k;

	while ((scanf(" %s", cpf) != EOF ))
	{
		//Retirar caracteres especiais;
		retiraPonto(cpf, cpfCpy);

		//Converter caractere para inteiro;
		transformaInt(cpfCpy, numCPF);

		for (i = 0, j = 1, k = 9; i < 9; i++, j++, k--)
		{	
			numB1 += numCPF[i] * j;
			numB2 += numCPF[i] * k;
		}

		numB1 = numB1 % 11;
		if (numB1 % 11 == 10)
			numB1 = 0;
		numB2 = numB2 % 11;
		if (numB2 % 11 == 10)
			numB2 = 0;

		if (numB1 == numCPF[9] && numB2 == numCPF[10])
			printf("CPF valido\n");
		else
			printf("CPF invalido\n");

		numB1 = 0;
		numB2 = 0;
	}
}

void transformaInt(char *str, short vet[])
{

	unsigned short i;

	for (i = 0; i < 11; i++)
		vet[i] = (int)str[i] - 48;

}

void retiraPonto(char *str, char *strCpy)
{

	short i = 0, j = 0;

	while (i < 14)
	{

		if (isdigit(str[i]))
			strCpy[j++] = str[i];

		i++;
	}

	strCpy[j] = '\0';
}