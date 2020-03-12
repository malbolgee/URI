/*

    @author: Malbolge;
    @date: 06/02/2020;
    @name: Indecisão das Renas;

*/

#include <stdio.h>

char *renas[] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};

int main(int argc, char **argv)
{

    int x;
    int soma = 0;
    for (int i = 0; i < 9; ++i)
        scanf("%d", &x), soma += x;

    printf("%s\n", renas[(soma - 1) % 9]);

    return 0;

}