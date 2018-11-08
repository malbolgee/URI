/*
	@autor: Malbolge;
	@data: 07/11/2018;
	@nome: Formatação Monetária;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inverte(char *);

void main ()
{

	char numeroStr[100], numeroVirgula[100];
	short i, j, contador;
	unsigned short moeda;
	unsigned numeroInt;

	while (scanf("%u %hu", &numeroInt, &moeda) != EOF)
	{

		// Passa um número inteiro para uma string;
		// Fazer isso, descarta quaisquer 0's no começo do número;
		sprintf(numeroStr, "%u", numeroInt);

		contador = 0;
		i = strlen(numeroStr) - 1;

		// Se for só uma string com o caracter '0'
		// Simplesmente imprima o resultado;
		if (strcmp(numeroStr, "0") == 0)
			printf("$0.%02hu\n", moeda);
		else
		{

			j = 0;
			while (i >= 0)
			{

				// A cada 3 numeros, imprima uma vírgula;
				if (contador % 3 == 0 && contador != 0)
					numeroVirgula[j++] = ',';

				// Enquanto isso, passe o que tem na string numeroStr
				// para a string numeroVirgula;
				numeroVirgula[j++] = numeroStr[i--];

				contador++;
			}

			// Coloca o caractere de final de string;
			numeroVirgula[j] = '\0';
			// Inverte a string de saída
			// Isso é necessário porque a string é preenchida de trás para frente;
			inverte(numeroVirgula);

			printf("$%s.%02hu\n", numeroVirgula, moeda);

			// Reseta o conteúdo das strings para a próxima iteração;
			memset(numeroStr, 0, sizeof(numeroStr));
			memset(numeroVirgula, 0, sizeof(numeroVirgula));

		}

	}

}

void inverte(char *numero)
{

	unsigned short i;
	short inicio, fim, meio;
	char aux;

	inicio = 0;
	fim = strlen(numero) - 1;
	meio = (strlen(numero) / 2) - 1;
	while (inicio <= meio)
	{

	    aux = numero[inicio];
	    numero[inicio] = numero[fim];
	    numero[fim] = aux;

	    inicio++;
	    fim--;

  	}

}
