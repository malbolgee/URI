/*

    @author: Malbolge;
    @date: 23/02/2020;
    @name: Supermercado;

*/

#include <stdio.h>

#define INF 0x3f3f3f3f

double min(double, double);

int main(int argc, char **argv)
{

    int n, cost;
    double gram, mim;

    scanf("%d", &n);

    mim = (double)INF;
    for (int i = 0 ; i < n; ++i)
    {

        scanf("%lf %d", &gram, &cost);
        mim = min(mim, (gram * 1000.0) / cost);
    
    }

    printf("%.2lf\n", mim);

    return 0;

}

double inline min(double a, double b)
{

    return a < b ? a : b;

}