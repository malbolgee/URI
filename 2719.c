/*
    @autor: Malbolge;
    @data: 13/03/2019;
    @nome: Quantas Viagens Fará o Noel?;
*/

#include <stdio.h>

#define true 1
#define false 0

typedef unsigned short us;

void main ()
{

    int t, n, m, i;

    scanf("%d", &t);

    while (t--)
    {

        scanf("%d %d", &n, &m);

        us viagens = 1;
        us peso, soma = 0;
        for (i = 0; i < n; ++i)
        {

            scanf("%hd", &peso);
            soma += peso;
            if (soma > m)
                ++viagens, soma = peso;

        }

        printf("%d\n", viagens);

    }

}