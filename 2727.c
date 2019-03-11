/*
    @autor: Malbolge;
    @data: 10/03/2019;
    @nome: Código Secreto;
*/

#include <stdio.h>

void main ()
{

    int n, i;
    char tmp;
    char codigo[150];

    while (scanf("%d", &n) != EOF)
    {

        scanf(" %[^\n]", codigo);

        char tmp2 = 0;
        for (i = 0; codigo[i]; ++i)
            if (codigo[i] == ' ')
                ++tmp2;

        tmp = 96;
        for (i = 0; codigo[i]; ++i)
            if (codigo[i] == ' ')
                break;
            else
                ++tmp;

        if (!tmp2)
            printf("%c\n", tmp);
        else
        {

            char letra;
            if (tmp2 == 1)
                letra = 3;
            else if (tmp2 == 2)
                letra = 6;
            else if (tmp2 == 3)
                letra = 9;
            else if (tmp2 == 4)
                letra = 12;
            else if (tmp2 == 5)
                letra = 15;
            else if (tmp2 == 6)
                letra = 18;
            else if (tmp2 == 7)
                letra = 21;
            else if (tmp2 == 8)
                letra = 24;

            printf("%c\n", letra + tmp);

        }

    }
            
}