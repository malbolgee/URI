/*
	@autor: Malboge;
	@data: 19/05/2019;
	@nome: Deli Deli;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct noArv{

	char string[50];
	char string_p[50];
	struct noArv *left;
	struct noArv *right;

} tree_t;

tree_t * push(tree_t *, char *, char *);
tree_t * search(tree_t *, char *);
void plural(char *);
_Bool check(char *, const int);

int main (int argc, char **argv)
{

	tree_t *t = NULL;
	unsigned i, l, n;
	char palavra[30], plural_p[20];

	scanf("%u %u", &l, &n);
	for (i = 0; i < l; ++i)
	{

		scanf("%s %s", palavra, plural_p);
		t = push(t, palavra, plural_p);

	}

	for (i = 0; i < n; ++i)
	{

		scanf("%s", palavra);
		tree_t *tmp = search(t, palavra);
		if (tmp)
			printf("%s\n", tmp->string_p);
		else
			plural(palavra);

	}

	return 0;

}

tree_t * push(tree_t *tree, char *s1, char *s2)
{

	if (!tree)
	{

		tree = (tree_t *) malloc(sizeof(tree_t));
		tree->left = tree->right = NULL;
		strcpy(tree->string, s1);
		strcpy(tree->string_p, s2);

	}
	else if (strcmp(tree->string, s1) < 0)
		tree->left = push(tree->left, s1, s2);
	else if (strcmp(tree->string, s1) > 0)
		tree->right = push(tree->right, s1, s2);

	return tree;

}

tree_t * search(tree_t *tree, char *s1)
{

	if (!tree)
		return NULL;

	if (strcmp(tree->string, s1) == 0)
		return tree;

	if (strcmp(tree->string, s1) < 0)
		return search(tree->left, s1);
	else if (strcmp(tree->string, s1) > 0)
		return search(tree->right, s1);

}

void plural(char *s1)
{

	int pos = strlen(s1);
	if (s1[pos - 2] != 'a' && s1[pos - 2] != 'e' && s1[pos - 2] != 'i' && s1[pos - 2] != 'o' && s1[pos - 2] != 'u' && s1[pos - 1] == 'y')
		s1[pos - 1] = 0, strcat(s1, "ies");
	else if (check(s1, pos))
		strcat(s1, "es");
	else
		strcat(s1, "s");

	printf("%s\n", s1);	

}

_Bool check(char *s1, const int size)
{

	if (s1[size - 1] == 'o')
		return true;
	
	if (s1[size - 1] == 's')
		return true;

	if (s1[size - 1] == 'x')
		return true;

	if (s1[size - 2] == 'c' && s1[size - 1] == 'h')
		return true;

	if (s1[size - 2] == 's' && s1[size - 1] == 'h')
		return true;

	return false;

}