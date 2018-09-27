/*
	@autor: Malbolge;
	@data: 26/09/2018;
	@nome: Entrada e Saída CPF;
*/

#include <stdio.h>
#include <ctype.h>

void imprimeCpf(char *, char *);

void main ()
{

	char cpf[15], saida[15], i;

	scanf("%s", cpf);

	imprimeCpf(cpf, saida);

	for (i = 0; saida[i]; i++)
	{
		if (i != 0 && i % 3 == 0)
			printf("\n");
		printf("%c", saida[i]);
	}
	printf("\n");


}

void imprimeCpf(char *str, char *saida)
{

	while (isdigit(*str))
		*(saida++) = *(str++);

	str++;
	while (isdigit(*str))
		*(saida++) = *(str++);

	str++;

	while (isdigit(*str))
		*(saida++) = *(str++);

	str++;

	while (isdigit(*str))
		*(saida++) = *(str++);

	*saida = '\0';

}