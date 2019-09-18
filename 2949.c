/*
    @autor: Malbolge;
    @data: 17/09/2019;
    @nome: A Sociedade do Anel;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{
    
    int n;
    char c;
    char nome[100];
    int ans[5] = { 0 };

    scanf("%d", &n);

    while (n--)
    {

        scanf("%s %c", nome, &c);

        if (c == 'X')
            ans[0]++;
        else if (c == 'H')
            ans[1]++;
        else if (c == 'E')
            ans[2]++;
        else if (c == 'A')
            ans[3]++;
        else
            ans[4]++;

    }

    printf("%d Hobbit(s)\n", ans[0]);
    printf("%d Humano(s)\n", ans[1]);
    printf("%d Elfo(s)\n", ans[2]);
    printf("%d Anao(s)\n", ans[3]);
    printf("%d Mago(s)\n", ans[4]);

    return 0;

}