/*
    @author: Malbolge;
    @date: 09/11/2020;
    @name: Figurinhas Repetidas;
*/

#include <stdio.h>

#define MAXSIZE 10123

int v[MAXSIZE];

int main(int argc, char **argv)
{

    int n, x;

    scanf("%d", &n);

    int r, d;
    r = d = 0;
    for (size_t i = 0; i < n; ++i)
    {

        scanf("%d", &x);

        !v[x] ? ++d : ++r;
        ++v[x];
    }

    printf("%d\n%d\n", d, r);

    return 0;
}