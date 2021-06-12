/*

    @author: Malbolge;
    @date: 12/06/2021;
    @problem: Dartboard;
    @subject: Probability;

*/

#include <stdio.h>
#include <math.h>

double var;

double f(double x)
{

    return exp(-x * x / (var * 2));
}

double prob(double r1, double r2)
{

    return f(r1) - f(r2);
}

int main()
{

    double radii[7] = {0.0};
    double expPts[] = {50.0, 25.0, 10.5, 31.5, 10.5, 21.0};

    for (int i = 1; i <= 6; ++i)
        scanf("%lf", &radii[i]);

    double stddev;
    scanf("%lf", &stddev);

    var = stddev * stddev;

    double expect = 0.0;

    for (int i = 0; i < 6; ++i)
        expect += (prob(radii[i], radii[i + 1]) * expPts[i]);

    printf("%.10g\n", expect);

    return 0;
}