/*
    @autor: Malbolge;
    @data: 17/09/2019;
    @nome: Credo com ParaTudo!;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 500

int par[MAXSIZE];

int parent(int);
char scanff(int *);

int main(int argc, char **argv)
{

    int m, p, n;
    int i, u, v, j, k;

    scanff(&n), scanff(&m), scanff(&p);

    for (i = 0; i <= n; ++i)
        par[i] = i;

    for (i = 0; i < m; ++i)
    {

        scanff(&u), scanff(&v);
        
        for (j = u; j != par[j]; j = par[j]);
        for (k = v; k != par[k]; k = par[k]);

        if (j == k)
            continue;

        par[j] = k;

    }

    while (p--)
    {

        scanff(&u), scanff(&v);

        u = parent(par[u]);
        v = parent(par[v]);

        if (par[u] == par[v])
            puts("Lets que lets");
        else
            puts("Deu ruim");

    }

    return 0;

}

int parent(int u)
{

    if (par[u] == u)
        return u;

    return parent(par[u]);

}

inline char scanff(int *a)
{

	register char c = 0;
	*a = 0;
	c = getchar_unlocked();

	while (c >= 48)
    	*a = *a * 10 + (c - '0'), c = getchar_unlocked();

    return c;

}