/*
    @author: Malbolge;
    @date: 08/07/2020;
    @name: O Grande Dia;
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

    char d;
    int x, y;
    int n, k, xf, yf, trap;
    scanf("%d %d %d %d%*c", &n, &k, &xf, &yf);

    trap = 1;
    x = y = 0;

    if (hypot(xf - 0, yf - 0) > (double)k)
    {
        printf("Trap %d\n", trap);
        return 0;
    }

    while (n--)
    {

        scanf(" %c", &d);

        if (d == 'C')
            ++y;
        else if (d == 'B')
            --y;
        else if (d == 'D')
            ++x;
        else if (d == 'E')
            --x;

        double dist = hypot(xf - x, yf - y);

        if (dist > (double)k)
        {
            printf("Trap %d\n", trap);
            return 0;
        }
        else if (dist == 0.0)
        {

            puts("Sucesso");
            return 0;
        }

        ++trap;
    }

    printf("Trap %d\n", trap - 1);

    return 0;
}