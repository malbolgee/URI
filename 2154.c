/*
	@autor: Malbolge;
	@data: 08/18/2018;
	@nome: Derivada de Pilinômios;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void parserDerivada(char *);

void main ()
{

	unsigned short i, j;
	unsigned short qtsTermos;
	char derivada[3000];

	while (scanf("%hu", &qtsTermos) != EOF)
	{

		scanf(" %[^\n]", derivada);

		parserDerivada(derivada);
		printf("\n");
		memset(derivada, 0, sizeof(derivada));

	}
}

void parserDerivada(char *derivada)
{

	unsigned short coeficiente, expoente;
	unsigned short resultado;
	unsigned short i, j;
	char temp[6];

	i = 0;
	while (derivada[i])
	{

		j = 0;
		memset(temp, 0, sizeof(temp));
		while (isdigit(derivada[i]))
			temp[j++] = derivada[i++];

		coeficiente = atoi(temp);

		i++;
		if (derivada[i] == 'x')
			i++;

		j = 0;
		memset(temp, 0, sizeof(temp));
		while (isdigit(derivada[i]))
			temp[j++] = derivada[i++];

		expoente = atoi(temp);
		i++;

		resultado = coeficiente * expoente;
		expoente--;

		if (expoente < 2)
			printf("%hux", resultado);
		else
			printf("%hux%hu", resultado, expoente);

		while (!isdigit(derivada[i]) && derivada[i] != '\0')
			i++;

		if (derivada[i] != '\0')
			printf(" + ");

	}

}
