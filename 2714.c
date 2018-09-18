/*
	@autor: Malbolge;
	@data: 17/09/2018;
	@nome: Minha Senha Provisória;
*/


#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool senhaFixa(char *);
void pegaNum(char *, char *);

void main ()
{	

	char regAcademico[21], numeros[20], lixo;
	unsigned short casos;

	scanf("%hu", &casos);
	scanf("%c", &lixo); // Trata o buffer do scanf anterior;

	while (casos--)
	{

		scanf("%s", regAcademico);
		scanf("%c", &lixo); // Trata o buffer do scanf anteior, visto que outras strings vão ser dadas como entrada;

		if (senhaFixa(regAcademico))
		{
			pegaNum(regAcademico,numeros);
			printf("%s\n", numeros);
		}
		else
			printf("INVALID DATA\n");


	}
}

bool senhaFixa(char *str)
{

	unsigned short tam;

	tam = strlen(str);
	
	if (tam != 20)
		return false;
	if (*str != 'R' && *(++str) != 'A') // Caso não haja um 'R' na primeira posição e um 'A' na segunda, string é inválida;
		return false;

	str += 2;
	while (*str)
	{	
		// Caso todos os dígitos restantes sejam números, então string é válida;
		if (!isdigit(*str)) 
			return false;

		str++;

	}

	return true;

}

void pegaNum(char *str, char *str2)
{

	unsigned short tam;	

	// Não há necessidade de testar as duas primeiras posições uma vez que não há números nelas;
	// E isso faria o primeio laço while falhar pois 'R' e 'A' são != 0;
	str += 2; 	

	// Esse laço elimita todos os 0's à direita da string;
	while (*str == '0')
		str++;

	// Captura todos os dígitos restantes a partir do último zero do laço anterior;
	// Dessa forma, mesmo que haja 0's nas posições subsequêntes, estes serão colocados na string final;
	while (*str)
		*(str2++) = *(str++);
	

	// Caractere nulo na posição atual para marcar o fim da string;
	*str2 = '\0';
}