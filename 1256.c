/*
	@autor: Malbolge;
	@data: 18/04/2019;
	@nome: Tabelas Hash;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_list{

	int data;
	struct node_list *next;

} node_list;

typedef struct l_list{

	node_list *first;
	node_list *last;

} l_list;

void hash_push(l_list *, const int);
unsigned x;

void main ()
{

	unsigned n;
	node_list *j;
	int y, i, tmp;

	scanf("%u", &n);

	while (n--)
	{

		scanf("%u %d", &x, &y);

		l_list hash[x];
		for (i = 0; i < x; ++i)
			hash[i].first = NULL, hash[i].last = NULL;

		for (i = 0; i < y; ++i)
			scanf("%d", &tmp), hash_push(hash, tmp);

		for (i = 0; i < x; ++i)
		{	
			printf("%d -> ", i);
			for (j = hash[i].first; j; j = j->next)
				printf("%d -> ", j->data);

			printf("\\");
			printf("\n");

		}

		if (n)
			printf("\n");

	}

}

void hash_push(l_list *__hash, const int key)
{

	node_list *aux;
	aux = (node_list *) malloc(sizeof(node_list));

	if(!aux)
		exit(1);

	int idx = key % x;
	if (__hash[idx].first)
		__hash[idx].last->next = aux;
	else
		__hash[idx].first = aux;

	__hash[idx].last = aux;
	aux->next = NULL;
	aux->data = key;
	
}
