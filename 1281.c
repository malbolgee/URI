/*
    @autor: Malbolge;
    @data: 08/11/2018;
    @nome: Ida à Feira;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

    char nome[100];
    float preco;

} fruta;

bool procuraFruta(fruta *, char *, unsigned short);
unsigned short posicao;

void main ()
{

    unsigned short qtsIdasFeira, qtsProdutos;
    unsigned short i, qtsProdutosDesejados;
    unsigned short quantidadeFrutas;
    char frutaStr[100];
    float somaPreco;

    scanf("%hu", &qtsIdasFeira);

    while (qtsIdasFeira--)
    {

        scanf("%hu", &qtsProdutos);

        fruta feira[qtsProdutos];
        for (i = 0; i < qtsProdutos; i++)
        {

            scanf(" %s", feira[i].nome);
            scanf("%f", &feira[i].preco);

        }

        scanf("%hu", &qtsProdutosDesejados);

        somaPreco  = 0;
        for (i = 0; i < qtsProdutosDesejados; i++)
        {
            scanf(" %s %hu", frutaStr, &quantidadeFrutas);
                if (procuraFruta(feira, frutaStr, qtsProdutos))
                    somaPreco += feira[posicao].preco * quantidadeFrutas;

        }

        printf("R$ %.2f\n", somaPreco);

    }

}

bool procuraFruta(fruta *feira, char *fruta, unsigned short tam)
{

    unsigned short i;

    for (i = 0; i < tam; i++)
        if (strcmp(feira[i].nome, fruta) == 0)
        {
            posicao = i;
            return true;
        }

    return false;

}
