/*
    @autor: Malbolge;
    @data: 24/07/2019;
    @nome: Dijkstra;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define SIZE 1000100

typedef struct noArv{

    char string[SIZE];
    struct noArv *left;
    struct noArv *right;

} noArv;

unsigned ans;

noArv * push(noArv *, char *);

int main(int argc, char **argv)
{

    char string[SIZE];

    noArv *arvore = NULL;
    while (scanf("%s", string) != EOF)
        arvore = push(arvore, string);

    printf("%d\n", ans);

    return 0;

}

noArv * push(noArv *tree, char *p)
{

    if (!tree)
    {

        tree = (noArv * ) malloc(sizeof(noArv));
        tree->left = tree->right = NULL;
        strcpy(tree->string, p);
        ++ans;

    }
    else if (strcmp(tree->string, p) > 0)
        tree->left = push(tree->left, p);
    else if (strcmp(tree->string, p) < 0)
        tree->right = push(tree->right, p);

    return tree;

}