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

	unsigned short casos, instrucoes, aux, i;
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
			//Só existem 3 comandos: "LEFT", "RIGHT" e "SAME AS i"
			//Por tanto, caso a entrada seja "SAME AS"
			//Eu sei que o primeiro caractere da string será 'S';
			else if(direcao[i].direcao[0], 'S')
			{	

				//O resultado da função pegaNum é então usado como índice em "direção[i].direcao"
				//Que é uma string;
				//Caso a string para a qual o resultado de pegaNum direciona
				//Torne essa condição verdadeira, então a variável 'posição' tem seu valor modificado
				//E o valor encontrado na string resultante tem seu valor "duplicado"
				//Na posição atual do struct;
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

/*
	A função pegaNum percorre a string caso a entrada
	seja "SAME AS" e avalia a parte numerica.
*/


short pegaNum(char *str)
{

	unsigned short i, j, contador = 0;
	unsigned short resultado = 0;
	short numero[3];

	while(str[i])
	{
		if (isdigit(str[i]))
		{

			contador++;
			numero[j++] = (int)str[i] - 48;

		}

		i++;
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