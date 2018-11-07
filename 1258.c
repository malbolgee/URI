/*
    @autor: Malbolge;
    @data: 06/11/2018;
    @nome: Camisetas;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

    char nome[60];
    char cor[20];
    char tamanho;

} camisa;

void ordenaTamanho(camisa *, unsigned short);
void ordenaAlpha(camisa *, unsigned short);
void ordenaCor(camisa *, unsigned short);

void main ()
{

    unsigned short qtsCamisetas;
    unsigned short i;

    scanf("%hu", &qtsCamisetas);

    while (true)
    {

        if (qtsCamisetas == 0)
            break;

        camisa camisas[qtsCamisetas];
        for (i = 0; i < qtsCamisetas; i++)
        {

            scanf(" %[^\n]", camisas[i].nome);
            scanf("%s %c", camisas[i].cor, &camisas[i].tamanho);

        }


        ordenaAlpha(camisas, qtsCamisetas);
        ordenaTamanho(camisas, qtsCamisetas);
        ordenaCor(camisas, qtsCamisetas);

        // Segundo teste de preenchimento;
        for (i = 0; i < qtsCamisetas; i++)
            printf("%s %c %s\n", camisas[i].cor, camisas[i].tamanho, camisas[i].nome);

        scanf("%hu", &qtsCamisetas);
        if (qtsCamisetas != 0)
            printf("\n");
    }

}

void ordenaAlpha(camisa *camisas, unsigned short tam)
{

    short i = 1, j;
    camisa pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = camisas[i];

        while (j >= 0 && strcmp(camisas[j].nome, pivo.nome) > 0)
        {

            camisas[j + 1] = camisas[j];
            j--;

        }
        camisas[j + 1] = pivo;
        i++;

    }

}

void ordenaCor(camisa *camisas, unsigned short tam)
{

    short i = 1, j;
    camisa pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = camisas[i];

        while (j >= 0 && strcmp(camisas[j].cor, pivo.cor) > 0)
        {

            camisas[j + 1] = camisas[j];
            j--;

        }
        camisas[j + 1] = pivo;
        i++;

    }

}

void ordenaTamanho(camisa *camisas, unsigned short tam)
{

    short i = 1, j;
    camisa pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = camisas[i];

        while (j >= 0 && camisas[j].tamanho < pivo.tamanho)
        {

            camisas[j + 1] = camisas[j];
            j--;

        }
        camisas[j + 1] = pivo;
        i++;

    }

}
