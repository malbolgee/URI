/*
	@autor: Malbolge;
	@data: 16/01/2019;
	@nome: Operações em ABP I;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 100

typedef struct noArv{

	char letra;
	struct noArv *esquerda;
	struct noArv *direita;

} noArv;

void infixa(noArv *);
void prefixa(noArv *);
void posfixa(noArv *);
void printInfixa(char *);
void printPrefixa(char *);
void printPosfixa(char *);
noArv* push(noArv *, char );
_Bool busca(noArv *, char );

char letrasInfixa[MAXSIZE] = { 0 };
char letrasPosfixa[MAXSIZE] = { 0 };
char letrasPrefixa[MAXSIZE] = { 0 };

int i = 0;
int j = 0;
int k = 0;

void teste(noArv *no)
{

	if (no)
	{

		teste(no->esquerda);
		printf("%c ", no->letra);
		teste(no->direita);

	}

}

void main ()
{

	char comando[20], letra;

	noArv *no = NULL;
	while (scanf("%s%*c", comando) != EOF)
	{

		if (strcmp(comando, "I") == 0)
		{

			scanf("%c", &letra);
			no = push(no, letra);

		}
		else if (strcmp(comando, "INFIXA") == 0)
			infixa(no), printInfixa(letrasInfixa);
		else if (strcmp(comando, "PREFIXA") == 0)
			prefixa(no), printPrefixa(letrasPrefixa);
		else if (strcmp(comando, "P") == 0)
		{

			scanf("%c", &letra);
			if (busca(no, letra))
				printf("%c existe\n", letra);
			else
				printf("%c nao existe\n", letra);

		}
		else
			posfixa(no), printPosfixa(letrasPosfixa);

	}

}

noArv* push(noArv *no, char letra)
{

	if (!no)
	{

		no = (noArv *) malloc(sizeof(noArv));
		no->letra = letra;
		no->direita = no->esquerda = NULL;

	}
	else if (no->letra > letra)
		no->esquerda = push(no->esquerda, letra);
	else
		no->direita = push(no->direita, letra);

	return no;

}

_Bool busca(noArv *no, char letra)
{

	_Bool direita, esquerda;

	if (!no)
		return false;

	if (no->letra == letra)
		return true;

	if (no->letra > letra)
		esquerda = busca(no->esquerda, letra);
	else
		direita = busca(no->direita, letra);

}

void printInfixa(char *letras)
{

	int z;
	for (z = 0; z < i; ++z)
		if (!z)
			printf("%c", letrasInfixa[z]);
		else
			printf(" %c", letrasInfixa[z]);

	i = 0;
	printf("\n");

}

void printPrefixa(char *letras)
{

	int z;
	for (z = 0; z < k; ++z)
		if (!z)
			printf("%c", letrasPrefixa[z]);
		else
			printf(" %c", letrasPrefixa[z]);

	k = 0;
	printf("\n");

}

void printPosfixa(char *letras)
{

	int z;
	for (z = 0; z < j; ++z)
		if (!z)
			printf("%c", letrasPosfixa[z]);
		else
			printf(" %c", letrasPosfixa[z]);

	j = 0;
	printf("\n");

}

void infixa(noArv *no)
{

	if (no)
	{

		infixa(no->esquerda);
		letrasInfixa[i++] = no->letra;
		infixa(no->direita);

	}

}

void posfixa(noArv *no)
{

	if (no)
	{

		posfixa(no->esquerda);
		posfixa(no->direita);
		letrasPosfixa[j++] = no->letra;

	}

}

void prefixa(noArv *no)
{

	if (no)
	{

		letrasPrefixa[k++] = no->letra;
		prefixa(no->esquerda);
		prefixa(no->direita);

	}

}
