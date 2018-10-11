/*
    @autor: Malbolge;
    @data: 10/10/2018;
    @nome: Sedex Marciano;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

    unsigned short largura, altura, profundidade, raio;
    double diagonal;

    scanf("%hu %hu %hu %hu", &largura, &altura, &profundidade, &raio);

    raio = raio + raio;

    diagonal = sqrt((largura*largura) + (altura * altura) + (profundidade * profundidade));

    if (diagonal <= raio)
        printf("S\n");
    else
        printf("N\n");

}
