/*

    @author: Malbolge;
    @date: 21/02/2020;
    @name: Cor da camisa;

*/

#include <stdio.h>
#include <math.h>

#define C 300000000

int main(int argc, char **argv)
{

    double speed;
    scanf("%lf", &speed);

    double lambda = 700.0 * (sqrt((C - speed) / (C + speed)) - 1.0) + 700.0;

    if (lambda < 400.0)
        puts("invisivel");
    else if (lambda < 425.0)
        puts("violeta");
    else if (lambda < 445.0)
        puts("anil");
    else if (lambda < 500.0)
        puts("azul");
    else if (lambda < 575.0)
        puts("verde");
    else if (lambda < 585.0)
        puts("amarelo");
    else if (lambda < 620.0)
        puts("laranja");
    else if (lambda < 750.0)
        puts("vermelho");
    else
        puts("invisivel");

    return 0;

}