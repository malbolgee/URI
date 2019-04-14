/*
	@autor: Malbolge;
	@data: 07/04/2019;
	@nome: Operações em ABP II;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct noArv{

	unsigned data;
	struct noArv *left;
	struct noArv *right;

} noArv;

_Bool flag;
void infixa(noArv *);
void prefixa(noArv *);
void posfixa(noArv *);
noArv * pop(noArv *, int);
_Bool busca(noArv *, int);
noArv * push(noArv *, int);
noArv * findMax(noArv *root);
noArv * findMin(noArv *root);

void main ()
{

	int num;
	char comando[10];
	noArv *root = NULL;

	while (scanf("%s%*c", comando) != EOF)
	{

		if (strcmp(comando, "I") == 0)
			scanf("%d%*c", &num), root = push(root, num);
		else if (strcmp(comando, "P") == 0)
		{

			scanf("%d%*c", &num);

			if (busca(root, num))
				printf("%d existe\n", num);
			else
				printf("%d nao existe\n", num);

		}
		else if (strcmp(comando, "R") == 0)
			scanf("%d%*c", &num), root = pop(root, num);
		else
		{
			
			flag = true;
			if (strcmp(comando, "INFIXA") == 0)
				infixa(root), printf("\n");
			else if (strcmp(comando, "PREFIXA") == 0)
				prefixa(root), printf("\n");
			else if (strcmp(comando, "POSFIXA") == 0)
				posfixa(root), printf("\n");

		}
		
	}

}

noArv* push(noArv *root, int data)
{

	if (!root)
	{

		root = (noArv *) malloc(sizeof(noArv));
		root->data = data;
		root->right = root->left = NULL;

	}
	else if (root->data < data)
		root->right = push(root->right, data);
	else
		root->left = push(root->left, data);
	
	return root;

}

_Bool busca(noArv *root, int chave)
{

	_Bool right, left;

	if (!root)
		return false;

	if (root->data == chave)
		return true;

	if (root->data < chave)
		right = busca(root->right, chave);
	else
		left = busca(root->left, chave);

}

void infixa(noArv *root)
{

	if (root)
	{

		infixa(root->left);
		if (!flag)
			printf(" %d", root->data);
		else
			printf("%d", root->data), flag = false;

		infixa(root->right);

	}

}

void prefixa(noArv *root)
{


	if (root)
	{

		if (!flag)
			printf(" %d", root->data);
		else
			printf("%d", root->data), flag = false;

		prefixa(root->left);
		prefixa(root->right);

	}
}

void posfixa(noArv *root)
{

	if (root)
	{

		posfixa(root->left);
		posfixa(root->right);

		if (!flag)
			printf(" %d", root->data);
		else
			printf("%d", root->data), flag = false;
	}

}

noArv * findMin(noArv *root)
{

	if (!root)
		return NULL;
	else if (!root->left)
		return root;
	else
		return findMin(root->left);

}

noArv * findMax(noArv *root)
{

	if(!root)
		return NULL;
	else if (!root->right)
		return root;
	else
		return findMax(root->right);

}

noArv * pop(noArv *root, int x)
{

	noArv *tmp;
	if (!root)
		return NULL;
	else if (root->data > x)
		root->left = pop(root->left, x);
	else if (root->data < x)
		root->right = pop(root->right, x);
	else if (root->left && root->right)
	{

		tmp = findMax(root->left);
		root->data = tmp->data;
		root->left = pop(root->left, root->data);

	}
	else
	{

		tmp = root;
		if (!root->left)
			root = root->right;
		else if (!root->right)
			root = root->left;

		free(tmp);

	}

	return root;

}
