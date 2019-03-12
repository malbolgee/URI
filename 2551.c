/*
    @autor: Malbolge;
    @data: 11/03/2019;
    @nome: Novo Recorde;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 40
#define INF 0x3f3f3f3f

float medias[MAXSIZE];

void main ()
{

    float x, y;
    unsigned short n, i;

    while (scanf("%hd", &n) != EOF)
    {

        for (i = 1; i <= n; ++i)
            scanf("%f %f", &x, &y), medias[i] = y / x;

        printf("1\n");
        float maior = medias[1];
        for (i = 2; i <= n; ++i)
            if (medias[i] > maior)
                maior = medias[i], printf("%d\n", i);

    }

}