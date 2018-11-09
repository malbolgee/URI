/*
    @autor: Malbolge;
    @data: 08/11/2018;
    @nome: Vogais Alienígenas;
*/

#include <stdio.h>
#include <string.h>

unsigned short contaVogais(char *, char *);

void main ()
{

    unsigned short i;
    char vogais[500], texto[1000];

    while (scanf(" %[^\n]", vogais) != EOF)
    {

        scanf(" %[^\n]", texto);
        printf("%hu\n", contaVogais(vogais, texto));

        memset(vogais, 0, sizeof(vogais));
        memset(texto, 0, sizeof(texto));

    }

}

unsigned short contaVogais(char *vogais, char *texto)
{

    unsigned short i, j;
    unsigned short qtsVogais;

    i = 0;
    qtsVogais = 0;
    while (vogais[i])
    {

        j = 0;
        while (texto[j])
        {

            if (vogais[i] == texto[j])
                qtsVogais++;

            j++;
        }

        i++;

    }

    return qtsVogais;

}
