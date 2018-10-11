/*
	@autor: Malbolge;
	@data: 10/10/2018;
	@nome: Árvore de Natal;
*/

#include <stdio.h>

void main ()
{

    short tamaho, i, j, z;

    while (scanf("%hu", &tamaho) != EOF)
    {

        for (i = 0; i < tamaho; i += 2)
        {
            for (j = 0; j < (tamaho - i) / 2; j++)
                printf(" ");

            for (z = i; z >= 0; z--)
                printf("*");

            printf("\n");

        }

        for (i = 0; i < tamaho/2; i++)
            printf(" ");
        printf("*\n");

        for (i = 1; i < tamaho/2; i++)
            printf(" ");

        printf("***\n\n");

    }
}
