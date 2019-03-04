/*
    @autor: Malbolge;
    @data: 04/03/2019;
    @nome: Melhor Ordem;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 500500
#define INF 9223372036854775807

typedef long long ll;

ll n;
ll vet[MAXSIZE];
ll _lis[MAXSIZE];

ll lis();

void main ()
{

    ll i;
    while (scanf("%lld", &n) != EOF)
    {

        for (i = 0; i < n; ++i)
            scanf("%lld", &vet[i]);

        printf("%lld\n", lis());

    }

}

ll lis()
{

    ll i;

    memset(_lis, INF, (sizeof(_lis)));
    _lis[0] = -INF;

    ll LisLength = 0;

    for (i = 0; i < n; ++i)
    {

        ll low, hi, mid;
        low = 0;
        hi = LisLength;

        while (low <= hi)
        {

            mid = (low + hi) / 2;
            if (_lis[mid] < vet[i])
                low = mid + 1;
            else
                hi = mid - 1;

        }

        _lis[low] = vet[i];
        if (LisLength < low)
            LisLength = low;

    }

    return LisLength;

}