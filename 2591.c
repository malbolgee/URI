/*
	@autor: Malbolge;
	@data: 21/09/2018;
	@nome: HameKameKa;
*/

#include <stdio.h>
#include <string.h>

void kameHame(char *, char *);

void main ()
{

	// A string de saída poderá ser muito maior do que a string de entrada;
	char palavra[201], saida[100000];
	unsigned short casos;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s", palavra);

		// Para não perder tempo, caso a string de entrada seja a string base "hamekame"
		// a resposta será apenas "ka" sem precisar chamar a função que resolve isso;
		if (strcmp(palavra, "hamekame") == 0)
			printf("ka\n");
		else
		{
			kameHame(palavra, saida);
			printf("%s\n", saida);
		}
	}
}

void kameHame(char *str, char *str2)
{
	unsigned short contador = 0, aux;

	// A primeira posição da string de saída recebe o caractere 'k';
	*str2 = 'k';
	// Incrementa a string de entrada e a string de saída em uma posição;
	str2++;
	str++;

	// Conta quantos caracteres 'a' existe(m) na primeira parte da string de entrada;
	// A quantidade de caracteres 'a' nessa parte vai definir a quantidade de caracteres 'a' na string de saída;
	while (*str == 'a')
	{
		str++;
		contador++;
	}

	while (*str != 'a')
		str++;

	// Se a quantidade de caracteres 'a' na primeira parte foi igual a 1
	// Então a quantidade de 'a' na string de saída é igual a da segunda parte da string de entrada;
	if (contador == 1)
	{

		while (*str == 'a')
			*(str2++) = *(str++);

		while (*str)
			str++;

		*str2 = '\0';
	}
	else
	{	
		// Caso contrário, cada 'a' da segunda parte da string de entrada vale a quantidade de 'a' da primeira parte;
		while (*str == 'a')
		{	
			aux = contador;
			while (aux-- > 0)
				*(str2++) = 'a';

			str++;
		}
	}

	*str2 = '\0';

}