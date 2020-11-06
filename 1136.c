/*
    @author: Malbolge;
    @date: 05/11/2020;
    @name: Bingo!;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100009

int c[MAXSIZE];
int v[MAXSIZE];

int main(int argc, char **argv)
{

    int n, b;
    while (scanf("%d %d", &n, &b), n)
    {

        for (size_t i = 0; i < b; ++i)
        {

            scanf("%d", &v[i]);
            for (size_t j = 0; j <= i; ++j)
                c[abs(v[i] - v[j])] = 1;
        }

        size_t i = 0;
        for (; i <= n; ++i)
            if (!c[i])
                break;

        printf("%c\n", (i - 1UL) != n ? 'N' : 'Y');
        memset(c, 0, sizeof(int) * (n + 1));
    }

    return 0;
}