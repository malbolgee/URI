/*
    @autor: Malbolge;
    @data: 14/03/2019;
    @nome: Flecha no Coelho;
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define PIE 3.14159265358979323846

void main ()
{

    double angulo, distancia, altura;
    while (scanf("%lf %lf %lf", &altura, &distancia, &angulo) != EOF)
        printf("%.4lf\n", altura + tan((angulo - 90.0F) * (PIE / 180.0F)) * distancia);

}
