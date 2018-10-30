/*
	@autor: Malbolge;
	@data: 29/10/2018;
	@nome: Teclado Zoeiro;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

	char teclasOriginais;
	char teclasTrocadas;

} teclado;

void trocaLetras(char *string, teclado *teclas, unsigned short tam);
bool foiTrocada(teclado *teclas, char letra, unsigned short tam);
char fazTroca(teclado *teclas, char letra, unsigned short tam);

void main ()
{

	unsigned short numTeclasTrocadas;
	unsigned short numFrases;
	unsigned short i;
	char frase[100];

	scanf("%hu %hu", &numTeclasTrocadas, &numFrases);

	// Vetor da struct do tipo Teclado;
	teclado teclas[numTeclasTrocadas];

	// preenche a struct;
	for (i = 0; i < numTeclasTrocadas; i++)
		scanf(" %c %c", &teclas[i].teclasOriginais, &teclas[i].teclasTrocadas);

	while (numFrases--)
	{

		scanf(" %[^\n]", frase);

		trocaLetras(frase, teclas, numTeclasTrocadas);

		printf("%s\n", frase);

		memset(frase, 0, sizeof(frase));

	}

}

// Função trocas as letras pelas correspondentes trocadas;
void trocaLetras(char *string, teclado *teclas, unsigned short tam)
{

	unsigned short i = 0;

	while (string[i])
	{

		if (foiTrocada(teclas, string[i], tam))
			string[i] = fazTroca(teclas, string[i], tam);

		i++;
	}

}

// Função verifica se a letra foi trocada;
bool foiTrocada(teclado *teclas, char letra, unsigned short tam)
{

	unsigned short i = 0;

	for (i = 0; i < tam; i++)
		if (letra == teclas[i].teclasOriginais || letra == teclas[i].teclasTrocadas)
			return true;

	return false;

}

// Função seleciona qual letra deve ser trocada;
char fazTroca(teclado *teclas, char letra, unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (letra == teclas[i].teclasOriginais || letra == teclas[i].teclasTrocadas)
			if (letra == teclas[i].teclasOriginais)
				return teclas[i].teclasTrocadas;
			else
				return teclas[i].teclasOriginais;

}
