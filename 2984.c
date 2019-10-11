/*
    @autor: Malbolge;
    @data: 08/10/2019;
    @nome: Assuntos Pendentes;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{   

    int i, j;
    char string[100100];

    scanf("%s", string);

    for (i = 0; string[i]; ++i)
    {

        if (string[i] != '(')
            continue;

        for (j = i + 1; string[j]; ++j)
        {

            if (string[j] == ')')
            {

                string[i] = 'X';
                string[j] = 'X';
                break;

            }

        }

    }

    int ans = 0;
    for (i = 0; string[i]; ++i)
        if (string[i] == '(')
            ++ans;

    if (ans == 0)
        puts("Partiu RU!");
    else
        printf("Ainda temos %d assunto(s) pendente(s)!\n", ans);
    
    return 0;

}