/*
	@autor: Malbolge;
	@data: 06/06/2019;
	@nome: Número de Erdos;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

#define INF 0x3f3f

typedef struct{

	char nome[20];
	unsigned erdos;

} autor_t;

char grid[101][101];
autor_t autores[101];

unsigned autores_n, artigos_n, tmp = 1;

void ascan();
void erdos_n();
void imprime();
int idx_a(char *);
int compara(autor_t *, autor_t *);

int main(int argc, char **argv)
{

	while (scanf("%u", &artigos_n), artigos_n)
	{

		autores_n = 0;
		memset(grid, 0,sizeof(grid));

		while (artigos_n--)
			ascan();

		erdos_n();
		imprime();

	}

	return 0;

}

void ascan()
{

	char nome[20];
	int n, i, j, out, autores_i[10];

	n = 0;
	do
	{

		scanf("%s %s", nome, &nome[3]);
		nome[2] = ' ';
		out = nome[strlen(nome) - 1] == '.';
		nome[strlen(nome) - 1] = '\0';
		autores_i[n++] = idx_a(nome);

	} while (!out);

	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			grid[autores_i[i]][autores_i[j]] = grid[autores_i[j]][autores_i[i]] = true;
	
}

void erdos_n()
{

	int fila[101], fila_i = 0, fila_f = 1, i, j;

	fila[0] = idx_a("P. Erdos");
	autores[fila[0]].erdos = 0;

	while (fila_f > fila_i)
	{

		i = fila[fila_i++];
		for (j = 0; j < autores_n; ++j)
			if (grid[i][j] && autores[j].erdos == INF)
				autores[j].erdos = autores[i].erdos + 1, fila[fila_f++] = j;

	}

}

int idx_a(char *nome)
{

	int i;
	for (i = 0; i < autores_n; ++i)
		if (strcmp(nome, autores[i].nome) == 0)
			return i;

	strcpy(autores[autores_n].nome, nome);
	autores[autores_n].erdos = INF;

	return autores_n++;

}

void imprime()
{

	int i;

	qsort(autores, autores_n, sizeof(autor_t), compara);
	printf("Teste %u\n", tmp++);

	for (i = 0; i < autores_n; ++i)
		if (strcmp(autores[i].nome, "P. Erdos") != 0)
			if (autores[i].erdos == INF)
				printf("%s: infinito\n", autores[i].nome);
			else
				printf("%s: %u\n", autores[i].nome, autores[i].erdos);

	printf("\n");

}

int compara(autor_t *a, autor_t *b)
{

	int ans;
	if ((ans = strcmp(&(a->nome[3]), &(b->nome[3]))) != 0)
		return ans;

	return a->nome[0] - b->nome[0];

}