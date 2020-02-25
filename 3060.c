/*

    @author: Malbolge;
    @date: 23/02/2020;
    @name: Parcelamento sem juros;

*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int v, p;

    scanf("%d %d", &v, &p);

    if (v % p == 0)
    {
        int x = v / p;
        for (int i = 0; i < p; ++i)
            printf("%d\n", x);

    }
    else
    {

        int x = v % p;
        int y = v / p;
        for (int i = 0; i < x; ++i)
            printf("%d\n", y + 1);

        for (int i = 0; i < p - x; ++i)
            printf("%d\n", y);

    }
    
    return 0;

}