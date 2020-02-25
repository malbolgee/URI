/*

    @autor: Malbolge;
    @data: 13/02/2020;
    @nome: Pares de Números;

*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int n, l, f;
    scanf("%d %d %d%*c", &n, &l, &f);

    int vet[n];

    for (int i = 0 ; i < n; ++i)
        scanf("%d", &vet[i]);

    int count = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (vet[i] != vet[j])
                if (vet[i] + vet[j] >= l && vet[i] + vet[j] <= f)
                    count += 1;

    printf("%d\n", count);

    return 0;

}