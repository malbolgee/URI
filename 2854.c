/*

	@autor: Malbolge;
	@data: 05/07/2019;
	@nome: Árvore Genealógica;

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noArv{

	char name[50];
	unsigned id;
	struct noArv *left;
	struct noArv *right;

} noArv;

#define true 1
#define false 0
#define MAXSIZE 310

char vis[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];

void dfs(const unsigned);
noArv *push(noArv *, char *);
int find(noArv *, char *);

unsigned idx;
unsigned m, n;

int main(int argc, char **argv)
{	

	int u, v, i, j;
	noArv *arvore = NULL;
	char name1[50], name2[50], conex[50];
	
	scanf("%u %u", &m, &n);
	int tmp = n;
	while (tmp--)
	{

		scanf("%s %s %s", name1, conex, name2);
		arvore = push(arvore, name1);
		arvore = push(arvore, name2);

		u = find(arvore, name1);
		v = find(arvore, name2);

		adj[u][v] = adj[v][u] = 1;	

	}

	int ans = 0;

	for (i = 1; i <= m; ++i)
		if (!vis[i])
			ans++, dfs(i);

	printf("%d\n", ans);

	return 0;

}

void dfs(const unsigned vertex)
{

	unsigned i;
	vis[vertex] = true;
	for (i = 1; i <= m; ++i)
		if (adj[vertex][i])
			if (!vis[i])
				dfs(i);

}

noArv *push(noArv *tree, char *str)
{

	if (!tree)
	{

		tree = (noArv *) malloc(sizeof(noArv));
		tree->left = tree->right = NULL;
		strcpy(tree->name, str);
		tree->id = ++idx;

	}
	else if (strcmp(tree->name, str) > 0)
		tree->left = push(tree->left, str);
	else if (strcmp(tree->name, str) < 0)
		tree->right = push(tree->right, str);
	
	return tree;

}

int find(noArv *tree, char *str)
{

	if (!tree)
		return -1;
	
	if (strcmp(tree->name, str) > 0)
		return find(tree->left, str);
	else if (strcmp(tree->name, str) < 0)
		return find(tree->right, str);
	else
		return tree->id;

}
