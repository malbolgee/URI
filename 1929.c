/*
    @autor: Malbolge;
    @data: 03/02/2019;
    @nome: Triângulo;
*/

#include <stdio.h>

#define true 1
#define false 0

_Bool triangulo(int, int, int);

void main ()
{

    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (triangulo(a, b, c))
        printf("S\n");
    else if (triangulo(a, b, d))
        printf("S\n");
    else if (triangulo(a, c, d))
        printf("S\n");
    else if (triangulo(b,c, d))
        printf("S\n");
    else
        printf("N\n");

}

_Bool triangulo(int a, int b, int c)
{

    int m, n, z;

    if (a >= b && a >= c)
        m = a, n = b, z = c;
    else
        if (b >= c)
            m = b, n = a, z = c;
        else
            m = c, n = a, z = b;

    if (m >= n + z)
        return false;

    return true;
    
}