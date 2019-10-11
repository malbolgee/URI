/*
    @autor: Malbolge;
    @data: 08/10/2019;
    @nome: Vamos Fechar;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int c, g;
    scanf("%d %d", &c, &g);

    if ((int)(c / g) < 10)
        printf("A UFSC fecha dia %d de setembro.\n", (c / g) + 21);
    else
        printf("A UFSC fecha dia %d de outubro.\n", (c / g) - 9);

    return 0;

}