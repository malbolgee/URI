/*
    @autor: Malbolge;
    @data: 02/03/2019;
    @nome: Digitador Gago;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 50
#define MAX 20000

typedef unsigned short us;

typedef struct string{

    char palavra[MAXSIZE];

} string;

string texto[1005];

void main ()
{
    char *tmp;
    int i, j;
    char teste[MAX] = { 0 };

    scanf("%[^\n]", teste);

    i = 0;
    tmp = strtok(teste, " ");
    strcpy(texto[i++].palavra, tmp);

    do
    {

        tmp = strtok('\0', " ");
        if (tmp)
            strcpy(texto[i++].palavra, tmp);

    } while (tmp);


    int k = 0;
    _Bool flag = false;
    for (j = 0; j < i; ++j)
        if (!flag)
        {
            if (strlen(texto[j].palavra) >= 4)
            {
                
                if (texto[j].palavra[k] == texto[j].palavra[k + 2] && texto[j].palavra[k + 1] == texto[j].palavra[k + 3])
                    printf("%s", &texto[j].palavra[k + 2]), flag = true;
                else
                    printf("%s", texto[j].palavra), flag = true;

            }
            else
                printf("%s", texto[j].palavra), flag = true;
        }
        else
        {

            if (strlen(texto[j].palavra) >= 4)
            {

                if (texto[j].palavra[k] == texto[j].palavra[k + 2] && texto[j].palavra[k + 1] == texto[j].palavra[k + 3])
                    printf(" %s", &texto[j].palavra[k + 2]), flag = true;
                else
                    printf(" %s", texto[j].palavra);

            }
            else
                printf(" %s", texto[j].palavra);

        }

    printf("\n");
        
}