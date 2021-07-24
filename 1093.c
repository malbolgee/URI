/*

    @author: Malbolge;
    @date: 23/07/2021;
    @problem: Vampiros;
    @subject: Math, Probability;

*/

#include <stdio.h>
#include <math.h>

double solve(int, int, int);

int main(int argc, char **argv)
{

    double prob;
    int ev1, ev2, at, d, tmp;

    while (scanf("%d %d %d %d", &ev1, &ev2, &at, &d), ev1 && ev2 && at && d)
    {

        tmp = ev1;
        ev1 = 0;
        while (tmp > 0)
            tmp -= d, ++ev1;

        tmp = ev2;
        ev2 = 0;
        while (tmp > 0)
            tmp -= d, ++ev2;

        prob = solve(ev1, ev2, at);
        printf("%.1f\n", prob * 100);
    }

    return 0;
}

double solve(int n1, int n2, int at)
{

    if (at == 3)
        return (double)n1 / (double)(n1 + n2);
    else
    {

        double p;
        p = 1.0 - (6 - at) / 6.0;
        p = (1 - p) / p;
        return (1.0 - pow(p, n1)) / (1.0 - pow(p, n1 + n2));
    }
}
