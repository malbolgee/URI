/*
    @autor: Malbolge;
    @data: 04/03/2019;
    @nome: Nomes de Usuários;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct noArv{

    char nome[120];
    struct noArv *direita;
    struct noArv *esquerda;

} noArv;

int ans;

noArv* push(noArv *, char *);

void main ()
{

    char *tmp;
    int n, i, j, ano;
    char aux[120], calouro[120];

    while (scanf("%d %d", &n, &ano) != EOF)
    {

        ans = 0;
        noArv *arvore = NULL;
        while (n--)
        {

            scanf(" %[^\n]", calouro);

            i = 0;
            tmp = strtok(calouro, " ");
            aux[i++] = tmp[0];

            do
            {

                tmp = strtok('\0', " ");
                if (tmp)
                    aux[i++] = tmp[0];

            } while (tmp);

            aux[i] = 0;
            arvore = push(arvore, aux);
        
        }

        printf("%d\n", ans);

    }
        
}

noArv* push(noArv *arvore, char *nome)
{

    if (!arvore)
    {

        arvore = (noArv *) malloc(sizeof(noArv));
        strcpy(arvore->nome, nome);
        arvore->esquerda = arvore->direita = NULL;

    }
    else if (strcmp(arvore->nome, nome) > 0)
        arvore->esquerda = push(arvore->esquerda, nome);
    else if (strcmp(arvore->nome, nome) < 0)
        arvore->direita = push(arvore->direita, nome);
    else
        ++ans;

    return arvore;

}
