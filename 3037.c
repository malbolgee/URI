/*
    @author: Malbolge;
    @date: 21/06/2020;
    @name: Jogando Dardos Por Distância;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int n;
    unsigned pts[2] = { 0 };

    scanf("%d", &n);

    int m, j;
    while (n--)
    {
        m = j = 3;
        unsigned x, d;
        pts[0] = pts[1] = 0;
        while (j--)
        {

            scanf("%u %u", &x, &d);
            pts[0] += x * d;

        }

        while (m--)
        {

            scanf("%u %u", &x, &d);
            pts[1] += x * d;

        }

        if (pts[0] > pts[1])
            puts("JOAO");
        else
            puts("MARIA");

    }

    return 0;
}