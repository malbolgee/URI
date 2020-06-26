/*
    @author: Malbolge;
    @date: 21/06/2020;
    @name: Relógio Antigo;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    unsigned a, b;

    while (~scanf("%u %u", &a, &b))
        printf("%02u:%02u\n", (a / 30U), (b / 6U));

    return 0;
}