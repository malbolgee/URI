/*
    @autor: Malbolge;
    @data: 02/03/2019;
    @nome: Grid de Largada;
*/

#include <stdio.h>

#define true 1
#define falas 0
#define MAXSIZE 30

void main ()
{

    int n, i, j;
    int chegada[MAXSIZE];
    int largada[MAXSIZE];
    int final[MAXSIZE];

    while (scanf("%d", &n) != EOF)
    {

        for (i = 0; i < n; ++i)
            scanf("%d", &largada[i]);

        for (i = 0; i < n; ++i)
            scanf("%d", &chegada[i]);

        for (i = 0; i < n; ++i)
            for (j = 0; j < n; ++j)
                if (largada[i] == chegada[j])
                {
                    final[j] = i + 1;
                    break;
                }

        // for (i = 0; i < n; ++i)
        //     printf("%d ", final[i]);

        int ultra = 0;
        for (i = 0; i < n; ++i)
            for (j = i + 1; j < n; ++j)
                if (final[i] > final[j])
                {

                    final[j] = final[j] ^ final[i];
                    final[i] = final[i] ^ final[j];
                    final[j] = final[j] ^ final[i];
                    ++ultra;

                }

        printf("%d\n", ultra);

    }

}