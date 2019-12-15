/*
    @autor: Malbolge;
    @data: 14/12/2019;
    @nome: 106 Milhas Para Chicago;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 110

inline double max(double, double);

int main(int argc, char **argv)
{

    int n, m;
    int i, j, k;

    while (scanf("%d", &n), n)
    {

        scanf("%d", &m);

        double prob[MAXSIZE][MAXSIZE] = {{ 0 }};

        while (m--)
        {
            
            scanf("%d %d %d", &i, &j, &k);
            prob[i][j] = prob[j][i] = k * 0.01;

        }

        for (i = 1; i <= n; ++i)
            for (j = 1; j < n; ++j)
                for (k = 1; k <= n; ++k)
                    prob[j][k] = max(prob[j][k], prob[j][i] * prob[i][k]);

        printf("%.6F percent\n", prob[1][n] * 100);

    }

    return 0;

}

double max(double a, double b)
{

    return a > b ? a : b;

}