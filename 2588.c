/*
    @autor: Malbolge;
    @data: 18/08/2019;
    @nome: Jogo dos Palíndromos;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{

    int c[200];
    int i, ans;
    char string[1010];

    while (scanf("%s", string) != EOF)
    {

        i = 0;
        memset(c, 0, sizeof(c));

        while (string[i])
            c[string[i++]]++;

        for (i = 0, ans = 0; i < 200; ++i)
            if (c[i] & 1)
                ++ans;

        printf("%d\n", ans <= 1 ? 0 : ans - 1);

    }

    return 0;

}