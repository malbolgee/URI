/*
    @autor: Malbolge;
    @data: 12/11/2018;
    @nome: Onde está o Mármore?;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int compara(const void *a, const void *b);
bool busca(unsigned *, unsigned, unsigned short);
int posicao;

void main ()
{

    unsigned short i, qtsCases;
    unsigned short qtsConsultas;
    unsigned qtsMarmores, numero;

    while (true)
    {

        scanf("%u %hu", &qtsMarmores, &qtsConsultas);

        if (qtsConsultas == 0 && qtsMarmores == 0)
            break;

        unsigned marmores[qtsMarmores];

        for (i = 0; i < qtsMarmores; i++)
            scanf("%u", &marmores[i]);

        qsort(marmores, qtsMarmores, sizeof(unsigned), compara);

        printf("CASE# %u:\n", ++qtsCases);
        while (qtsConsultas--)
        {

            scanf("%u", &numero);

            if (busca(marmores, numero, qtsMarmores))
            {

                if (marmores[posicao - 1] == marmores[posicao])
                {
                    while (marmores[posicao - 1] == marmores[posicao])
                        posicao--;

                    printf("%u found at %u\n", numero, posicao + 1);

                }
                else
                    printf("%u found at %u\n", numero, posicao + 1);

            }
            else
                printf("%u not found\n", numero);

        }

    }

}

// Função de comparação para o qsort;
int compara(const void *a, const void *b)
{

    if (*(unsigned*)a == *(unsigned *)b)
        return 0;
    else if (*(unsigned*)a > *(unsigned*)b)
        return 1;
    else
        return -1;

}

// Função implementa busca binária;
bool busca(unsigned *marmores, unsigned numero, unsigned short tam)
{

	int inicio, fim, meio;
	inicio = 0;
	fim = tam - 1;

	while(inicio <= fim)

	{
		meio = (inicio + fim) / 2;
		if (marmores[meio] < numero)
			inicio = meio + 1;
		else if(marmores[meio] > numero)
			fim = meio - 1;
		else
		{
			posicao = meio;
			return true;
		}

	}

	return false;
}
