/*
	@autor: Malbolge;
	@data: 23/09/2018;
	@nome: Soma de Propina;
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void cpfPropinaSrc(char *, char *, char *);
void secondSrc(char *, char *, char *);
unsigned short somaNum(short *, unsigned short);
unsigned short somaNumStr(char *vet);

void main ()
{

	char texto[122], texto2[61], cpf[12], propina[12];

	scanf("%s", texto);
	scanf(" %s", texto2);

	// Concatena a string 2 com a string 1;
	// Dessa forma, posso trabalhar com apenas uma string;
	strcat(texto, texto2);

	printf("%s\n", texto);
	cpfPropinaSrc(texto, cpf, propina);

	printf("cpf %s\n", cpf);
	printf("propina: %s\n", propina);

}

void cpfPropinaSrc(char *string, char *cpf, char *propina)
{

	unsigned short contador = 0;
	short i, *decimal;
	short numero, soma;

	decimal = (short*) malloc(sizeof(short) * 2);

	while (contador != 11)
	{

		if (isdigit(*string))
		{
			*(cpf++) = *(string++);
			contador++;
		}
		else
			string++;
	}

	*cpf = '\0';

	while (*string != '.')
	{
		if (isdigit(*string))
			*(propina++) = *(string++);
		else
			string++;
	}
	
	*propina = '\0';

	soma = somaNumStr(propina);
	printf("Esse é o valor de soma: %hu\n", soma);

	
	i = 0;
	string++;
	contador = 0;
	while (contador != 2)
	{

		decimal[i++] = (int) *string - 48;
		contador++;
		string++;

	}

	numero = somaNum(decimal, contador);
	printf("Esse é o resultado de soma num: %hu\n", numero);


}

unsigned short somaNum(short *vet, unsigned short tamanho)
{

	unsigned short numero = 0, aux;
	unsigned short i;

	for (i = 0, aux = tamanho; i < tamanho; i++, aux--)
	{

		if (aux == 3)
			numero += *(vet++) * 100;
		else if (aux == 2)
			numero += *(vet++) * 10;
		else if (aux == 1)
			numero += *(vet++);

	}

	return numero;

}

unsigned short somaNumStr(char *vet)
{

	unsigned short numero = 0, aux;
	unsigned short i, contador = 0;
	short decimal[10];

	i = 0;

	while (*vet)
	{

		decimal[i++] = (int) *vet - 48;
		contador++;
		vet++;

	}

	for (i = 0, aux = contador; i < contador; i++, aux--)
	{

		if (aux == 3)
			numero += *(vet++) * 100;
		else if (aux == 2)
			numero += *(vet++) * 10;
		else if (aux == 1)
			numero += *(vet++);

	}

	return numero;

}