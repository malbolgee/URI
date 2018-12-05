/*
	@autor: Malbolge;
	@data: 03/12/2018;
	@nome: Espécies de Madeira;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct tipoDado{

	char nome[100];
	unsigned qtsUnidades;

} tipoDado;

// Definição da estrutura de árvore binária;
typedef struct noArv{

	tipoDado dado;
	struct noArv *direita;
	struct noArv *esquerda;

} noArv;

noArv* push(noArv *arvore, tipoDado dado);
void show(noArv *arvore);
void erase(noArv *arvore);
unsigned qtsNos;

void main ()
{

	char lixo;
	unsigned qtsCasos;
	char string[100] = { 0 };

	// Tratamento para leitura das linhas em branco (string vazia);
	scanf("%u", &qtsCasos);
	scanf("%c%[^\n]", &lixo, string);

	while (qtsCasos)
	{

		qtsNos = 0;
		// Criação da raíz;
		noArv *arvore = NULL;
		while (true)
		{

			tipoDado dado = { 0 };
			// Leitura da string;
			scanf("%c%[^\n]", &lixo, string);

			// Se a string for vazia, quer dizer que tenho um caso novo;
			if (!strlen(string))
				break;

			// Copio a string para dentro da struct;
			// Insiro a struct na árvore;
			strcpy(dado.nome, string);
			arvore = push(arvore, dado);
			qtsNos++;
			// Reseto o conteúdo da string para a próxima iteração;
			memset(string, 0, sizeof(string));

		}

		qtsCasos--;
		show(arvore);
		erase(arvore);
		if (qtsCasos)
			printf("\n");

	}

}

// Função insere elementos na árvore;
noArv* push(noArv *arvore, tipoDado dado)
{


	if (!arvore)
	{

		arvore = (noArv *) malloc(sizeof(noArv));
		arvore->dado = dado;
		arvore->dado.qtsUnidades++;
		arvore->direita = arvore->esquerda = NULL;

	}
	else if (strcmp(arvore->dado.nome, dado.nome) > 0)
		arvore->esquerda = push(arvore->esquerda, dado);
	else if (strcmp(arvore->dado. nome, dado.nome) < 0)
		arvore->direita = push(arvore->direita, dado);
	else
		arvore->dado.qtsUnidades++;

	return arvore;

}

// Função mostra os elementos da árvore;
void show(noArv *arvore)
{


	if (arvore)
	{

		show(arvore->esquerda);
		printf("%s %.4lf\n", arvore->dado.nome, (arvore->dado.qtsUnidades * 100.0f) / qtsNos);
		show(arvore->direita);

	}

}

// Função apaga a árvore;
void erase(noArv *arvore)
{

	if (!arvore)
		return;

	erase(arvore->esquerda);
	erase(arvore->direita);
	free(arvore);
	arvore = NULL;

}
