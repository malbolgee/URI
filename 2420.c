/*
    @autor: Malbolge;
    @data: 26/03/2019;
    @nome: Guerra Por Território;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 100100

unsigned vet[MAXSIZE];

int bb(int, int);

void main ()
{


    unsigned n, i, tmp, somatotal;
    scanf("%u", &n);

    int soma;
    soma = somatotal = 0;
    scanf("%u", &vet[0]);
    somatotal += vet[0];
    for (i = 1; i < n; ++i)
    {

        scanf("%u", &tmp);
        vet[i] += vet[i - 1] + tmp;
        somatotal += tmp;

    }

    printf("%u\n", bb(somatotal / 2, n) + 1);

}

int bb(int key, int tam)
{

    int hi, low, mid;

    low = 0;
    hi = tam - 1;

    while (hi > low)
    {
        mid = low + ((hi - low) / 2);
        if (vet[mid] < key)
            low = mid + 1;
        else
            hi = mid;
    }

    return low;

}
