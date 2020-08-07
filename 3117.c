/*
    @author: Malbolge;
    @date: 10/07/2020;
    @name: Atrasadinhos;
*/

#include <stdio.h>

int main(int argc, char **argv)
{   

    int n, k, x;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
    {

        scanf("%d", &x);

        if (x <= 0)
            --k;

        if (k <= 0)
        {

            puts("YES");
            return 0;

        }

    }

    puts("NO");

    return 0;
}