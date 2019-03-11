/*
    @autor: Malbolge;
    @data: 10/03/2019;
    @nome: Aeroporto;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 105
#define INF 0x3f3f3f3f

int voos[MAXSIZE];

void main ()
{

    int i;
    int x, y;
    int n, m, teste = 0;

    while (scanf("%d %d", &n, &m), m && n)
    {

        for (i = 0; i < m; ++i)
            scanf("%d %d", &x, &y), voos[x]++, voos[y]++;

        int pos;
        int maior = -INF;

        printf("Teste %d\n", ++teste);

        for (i = 1; i <= n; ++i)
            if (voos[i] > maior)
                maior = voos[i];

        for (i = 1; i <= n; ++i)
            if (voos[i] == maior)
                printf("%d ", i);

        printf("\n\n");
        memset(voos, 0, sizeof(voos));

    }

}
