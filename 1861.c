/*
	@autor: Malbolge;
	@data: 29/11/2018;
	@nome: O Hall dos Assassinos;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipoDado{

	char nome[20];
	unsigned qtsMortes;

} Assassinos;

struct ArvHall{

	Assassinos dado;
	struct ArvHall *esquerdo;
	struct ArvHall *direito;

};

struct ArvMortos{

	char morto[20];
	struct ArvMortos *esquerdo;
	struct ArvMortos *direito;

};

typedef struct ArvHall Hall;
typedef struct ArvMortos Mortos;

Hall* insereAssassinos(Hall *, Assassinos);
Mortos* insereMortos(Mortos *, char *);
bool busca(Mortos *mortos, char *chave);
void show(Hall *, Mortos *);

void main ()
{

	char matou[20], morreu[20];
	Hall *hall = NULL;
	Mortos *mortos = NULL;

	while (scanf(" %s %s", matou, morreu) != EOF)
	{

		Assassinos assassino = { 0 };
		strcpy(assassino.nome, matou);
		hall = insereAssassinos(hall, assassino);
		mortos = insereMortos(mortos, morreu);

	}

	printf("HALL OF MURDERERS\n");
	show(hall, mortos);

}

Hall* insereAssassinos(Hall *hall, Assassinos assassino)
{

	if (!hall)
	{

		hall = (Hall *) malloc(sizeof(Hall));
		hall->dado = assassino;
		hall->dado.qtsMortes++;
		hall->esquerdo = hall->direito = NULL;

	}
	else if (strcmp(hall->dado.nome, assassino.nome) > 0)
		hall->esquerdo = insereAssassinos(hall->esquerdo, assassino);
	else if (strcmp(hall->dado.nome, assassino.nome) < 0)
		hall->direito = insereAssassinos(hall->direito, assassino);
	else
		hall->dado.qtsMortes++;

	return hall;

}

Mortos* insereMortos(Mortos *mortos, char *morto)
{

	if (!mortos)
	{

		mortos = (Mortos *) malloc(sizeof(Mortos));
		strcpy(mortos->morto, morto);
		mortos->esquerdo = mortos->direito = NULL;

	}
	else if (strcmp(mortos->morto, morto) > 0)
		mortos->esquerdo = insereMortos(mortos->esquerdo, morto);
	else
		mortos->direito = insereMortos(mortos->direito, morto);

	return mortos;

}

void show(Hall *hall, Mortos *mortos)
{

	if (hall != NULL)
	{

		show(hall->esquerdo, mortos);
		if (!busca(mortos, hall->dado.nome))
			printf("%s %u\n", hall->dado.nome, hall->dado.qtsMortes);
		show(hall->direito, mortos);

	}

}

bool busca(Mortos *mortos, char *chave)
{

	bool direita, esquerda;

	if (!mortos)
		return false;

	if (strcmp(mortos->morto, chave) == 0)
		return true;

	if (strcmp(mortos->morto, chave) > 0)
		esquerda = busca(mortos->esquerdo, chave);
	else
		direita = busca(mortos->direito, chave);

}
