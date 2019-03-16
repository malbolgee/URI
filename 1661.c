/*
    @autor: Malbolge;
    @data: 15/03/2019;
    @nome: Comércio de Vinhos na Gergóvia;
*/

#include <stdio.h>

#define ABS(a) a < 0 ? -a : a

typedef long long ll;

void main ()
{

    int n, i, custo;
    ll ans, carrega;
    while (scanf("%d", &n), n)
    {
        
        ans = carrega = 0;
        for (i = 0; i < n; ++i)
            scanf("%d", &custo), carrega += custo, ans += ABS(carrega);

        printf("%lld\n", ans);

    }

}