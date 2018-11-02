/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Tradutor do Papai Noel;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *paises[24] = { "brasil", "alemanha", "austria", "coreia", "espanha", "grecia", "estados-unidos",
			"inglaterra", "australia", "portugal", "suecia", "turquia", "argentina", "chile",
			"mexico", "antardida", "canada", "irlanda", "belgica", "italia", "libia", "siria",
			"marrocos", "japao" };
char *saudacoes[24] = { "Feliz Natal!", "Frohliche Weihnachten!", "Frohe Weihnacht!", "Chuk Sung Tan!",
				"Feliz Navidad!", "Kala Christougena!", "Merry Christmas!", "Merry Christmas!",
				"Merry Christmas!", "Feliz Natal!", "God Jul!", "Mutlu Noeller", "Feliz Navidad!",
				"Feliz Navidad!", "Feliz Navidad!", "Merry Christmas!", "Merry Christmas!", "Nollaig Shona Dhuit!",
				"Zalig Kerstfeest!", "Buon Natale!", "Buon Natale!", "Milad Mubarak!", "Milad Mubarak!", "Merii Kurisumasu!" };
typedef struct{

	char pais[50];
	char saudacao[100];

} tradutor;

tradutor traducao[24];
unsigned short posicao;

void preencheTradutor();
bool pesquisaPais(char *);

void main ()
{

	preencheTradutor();
	char pais[100];

	while (scanf(" %s", pais) != EOF)
	{

		if (pesquisaPais(pais))
			printf("%s\n", traducao[posicao].saudacao);
		else
			printf("--- NOT FOUND ---\n");

	}

}

void preencheTradutor()
{

	unsigned short i;

	for (i = 0; i < 24; i++)
	{
		strcpy(traducao[i].pais, paises[i]);
		strcpy(traducao[i].saudacao, saudacoes[i]);
	}

}

bool pesquisaPais(char *pais)
{

	unsigned short i;

	for (i = 0; i < 24; i++)
		if (strcmp(traducao[i].pais, pais) == 0)
		{
			posicao = i;
			return true;
		}

	return false;

}
