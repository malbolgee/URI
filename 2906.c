/*
    @autor: Malbolge;
    @data: 02/08/2019;
    @nome: Database of Clients;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct noArv{

    char email[100];
    struct noArv *left;
    struct noArv *right;

} noArv;

int ans;

void tp(char *);
noArv * push(noArv *, char *);

int main(int argc, char **argv)
{

    int n;
    char name[150];
    char provider[150];
    noArv *arvore = NULL;

    scanf("%d", &n);

    while (n--)
    {

        scanf(" %[^@]%s", name, provider);
        tp(name);
        strcat(name, provider);
        arvore = push(arvore, name);

    }

    printf("%d\n", ans);

    return 0;

}

void tp(char *str)
{

    int i, j;
    i = j = 0;
    char tmp[150];
    while (str[i])
    {

        if (str[i] != '.')
            tmp[j++] = str[i];

        i++;

    }

    tmp[j] = 0;

    j = 0;
    while (tmp[j])
        if (tmp[j] == '+')
        {

            tmp[j] = 0;
            break;

        }
        else
            j++;

    j = i = 0;
    while (tmp[j])
        str[i++] = tmp[j++];

    str[i] = 0;

}

noArv * push(noArv *tree, char *str)
{

    if (!tree)
    {

        tree = (noArv *) malloc(sizeof(noArv));
        tree->left = tree->right = NULL;
        strcpy(tree->email, str);
        ans++;

    }
    else if (strcmp(tree->email, str) > 0)
        tree->left = push(tree->left, str);
    else if (strcmp(tree->email, str) < 0)
        tree->right = push(tree->right, str);

    return tree;

}