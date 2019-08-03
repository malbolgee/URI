/*
    @autor: Malbolge;
    @data: 02/08/2019;
    @nome: A Symmetrical Pizza;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int gdc(int, int);

int main(int argc, char **argv)
{

    int x, y;
    scanf("%d.%d", &x, &y);
    printf("%d\n", 36000 / gdc(36000, 100 * x + y));

    return 0;
}

int gdc(int a, int b)
{

    if (b == 0)
        return a;
    else
        return gdc(b, a % b);

}