/*
    @autor: Malbolge;
    @data: 08/10/2019;
    @nome: Balão de Honra;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    char c;
    int i, j;
    char str[27];

    for (i = 'A', j = 1; i <= 'Z'; ++i, ++j)
        str[i] = j;

    scanf("%c", &c);
    printf("%d\n", str[c]);

    return 0;

}