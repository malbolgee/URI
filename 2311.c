/*

    @author: Malbolge;
    @date: 26/02/2020;
    @name: Saltos Ornamentais;

*/

#include <stdio.h>
#include <stdlib.h>

int compare(int *, int *);

double min(double, double);
double max(double, double);

int main(int argc, char **argv)
{

    int n;
    char string[100];
    double notas, x, maior, menor, grau;

    scanf("%d", &n);

    while (n--)
    {

        scanf("%s", string);
        scanf("%lf", &grau);
        
        notas = 0.0;
        maior = -1.0;
        menor = 11.0;
        for (int i = 0; i < 7; ++i)
        {

            scanf("%lf", &x);

            notas += x;
            maior = max(maior, x);
            menor = min(menor, x);


        }

        notas -= (menor + maior);
        printf("%s %0.2lf\n", string, notas *= grau);

    }


    return 0;
}

inline double min(double a, double b)
{

    return a < b ? a : b;

}

inline double max(double a, double b)
{

    return a > b ? a : b;

}