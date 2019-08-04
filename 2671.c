/*
    @autor: Malbolge;
    @data: 04/08/2019;
    @nome: Decodificando o Texto;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define SIZ 250

int k;
char ans[SIZ];
char string[SIZ];

void build(int, int);

int main(int argc, char **argv)
{

    int n;

    while (scanf("%d%*c", &n), n)
    {

        k = 0;
        scanf("%[^\n]", string);

        build(1, n);
        ans[k] = 0;
        printf("%s\n", ans);

    }

    return 0;

}

void build(int u, int n)
{

    if (u > n)
        return;

    build(2 * u, n);
    ans[u - 1] = string[k++];
    build(2 * u + 1, n);

}