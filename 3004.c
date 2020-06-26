/*
    @author: Malbolge;
    @date: 21/06/2020;
    @name: Envelopes;

*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int n;

    scanf("%d", &n);

    while (n--)
    {

        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if ((a < c && b < d) || (b < c && a < d))
            puts("S");
        else
            puts("N");

    }

    return 0;
}