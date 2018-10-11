/*
    @autor: Malbolge;
    @data: 10/10/2018;
    @nome: Gangorra;
*/

#include <stdio.h>

void main ()
{

    unsigned short peso1, crianca1, peso2, crianca2;

    scanf("%hu %hu %hu %hu", &peso1, &crianca1, &peso2, &crianca2);

    if (peso1*crianca1 == peso2*crianca2)
        printf("0\n");
    else if (peso1*crianca1 < peso2*crianca2)
        printf("1\n");
    else
        printf("-1\n");


}
