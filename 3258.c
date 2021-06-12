/*

    @author: Malbolge;
    @date: 21/06/2021;
    @problem: Fervendo Vegetais;
    @subject: PD;

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 1234

int n;
double ratio;
int values[MAXSIZE];

int solve(int, double, double, int);
int compare(const void *, const void *);

static inline double max(double a, double b)
{

    return a > b ? a : b;
}

static inline double min(double a, double b)
{

    return a < b ? a : b;
}

int main()
{

    scanf("%lf %d", &ratio, &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &values[i]);

    qsort(values, n, sizeof(int), compare);
    printf("%d\n", solve(0, values[0], values[0], 0));

    return 0;
}

int solve(int k, double curMin, double curMax, int curCuts)
{

    if (k == n)
        return curCuts;

    double absMax = curMin / ratio;
    double absMin = curMax * ratio;
    int low = (int)ceil(values[k] / absMax);
    int high = (int)(values[k] / absMin);

    if (k == 0)
        low = 1, high = values[0];

    for (int i = low; i <= high; ++i)
    {

        double newL = values[k] / i;

        if (k == 0)
            curMin = curMax = newL;

        int ans = solve(k + 1, min(curMin, newL), max(curMax, newL), curCuts + i - 1);
        if (ans != -1)
            return ans;
    }

    return -1;
}

int compare(const void *a, const void *b)
{

    return *(int *)a - *(int *)b;
}
