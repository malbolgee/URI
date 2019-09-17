/*
    @autor: Malbolge;
    @data: 17/09/2019;
    @nome: Ô, Que Tanto de Filme!;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct _cat{

    char string[150];
    char string2[150];

} cat;

int main(int argc, char **argv)
{

    int n, i;
    char string[20];
    cat categorias[5];
    int ans[5] = { 0 };

    scanf("%d%*c", &n);

    while (n--)
    {

        scanf("%s", string);

        for (i = 0; i < 4; ++i)
            scanf("%*c%[^\n]", categorias[i].string);

        scanf("%s", string);

        for (i = 0; i < 4; ++i)
            scanf("%*c%[^\n]", categorias[i].string2);

        for (i = 0; i < 4; ++i)
            if (strcmp(categorias[i].string, categorias[i].string2) == 0)
                ans[i]++;

    }

    int m = ans[0], cnt = 1;

    for (i = 1; i < 4; ++i)
        if (ans[i] < m)
            m = ans[i], cnt = 1;
        else if(ans[i] == m)
            cnt++;

    for (i = 0; i < 4; ++i)
        if (ans[i] == m)
            printf("%d%c", i + 1, --cnt ? ' ' : '\n');

    return 0;

}