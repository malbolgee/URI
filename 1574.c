/*
	@autor: Malbolge;
	@data: 09/09/2018;
	@nome: Instruções do Robô;
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{

	char direcao[10];

} string;

short pegaNum(char *str);

void main ()
{

	unsigned short casos, instrucoes, indice, numero = 0, aux, i = 1;
	short posicao = 0;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &instrucoes);

		aux = instrucoes;

		//vetor do tipo string;
		string direcao[aux + 1];
		posicao = 0;
		i = 1;

		while (instrucoes--)
		{

			scanf(" %[^\n]", direcao[i].direcao);

			if(strcmp(direcao[i].direcao, "LEFT") == 0)
			{
				posicao--;
				i++;
				
			}	
			else if (strcmp(direcao[i].direcao, "RIGHT") == 0)
			{
				posicao++;
				i++;
				
			}
			else if(direcao[i].direcao[0], 'S')
			{	

				if(strcmp(direcao[pegaNum(direcao[i].direcao)].direcao, "LEFT") == 0)
				{	

					posicao--;
					strcpy(direcao[i].direcao, "LEFT");
					i++;
				}
				
				else if(strcmp(direcao[pegaNum(direcao[i].direcao)].direcao, "RIGHT") == 0)
				{
					posicao++;
					strcpy(direcao[i].direcao, "RIGHT");
					i++;
				}
			}
		}
	

	printf("%hd\n", posicao);

	}
}


short pegaNum(char *str)
{

	unsigned short i, j, contador = 0;
	unsigned short resultado = 0;
	short numero[3], tam;

	tam = strlen(str);

	for (i = 0, j = 0; i < tam; i++)
		if (isdigit(str[i]))
		{

			contador++;
			numero[j++] = (int)str[i] - 48;

		}

		for (i = 0, j = contador; i < contador; i++, j--)
		{

			if (j == 3)
				resultado += numero[i] * 100;
			else if (j == 2)
				resultado += numero[i] * 10;
			else if (j == 1)
				resultado += numero[i];

		}

	return resultado;
}