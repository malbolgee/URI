/*
    @author: Malbolge;
    @date: 21/06/2020;
    @name: Nota Cortada;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    short b, t;
    scanf("%hd %hd", &b, &t);

    if (b > (160 - t))
        puts("1");
    else if (b < (160 - t))
        puts("2");
    else
        puts("0");

    return 0;
}