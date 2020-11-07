/*

    @author: Malbolge;
    @date: 06/11/2020;
    @name: Metrô Engenhoso;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 101009

int v[MAXSIZE];
char ans[MAXSIZE];

int gcd(int, int);
int compare(const void *, const void *);

int main(int argc, char **argv)
{

    size_t j;
    int t, q, g;

    while (scanf("%d %d", &t, &q), t)
    {

        for (size_t i = 0; i < t; ++i)
            scanf("%d", &v[i]);

        qsort(v, t, sizeof(int), compare);

        if (t > 1)
            g = v[1] - v[0];

        for (size_t i = 2; i < t; ++i)
            g = gcd(v[i] - v[i - 1], g);

        j = 0;
        bool pos;
        memset(ans, 0, sizeof(ans));

        while (q--)
        {

            int s, d;
            pos = false;
            scanf("%d %d", &s, &d);

            if ((s & 1) == (d & 1))
            {

                if (t == 1)
                    pos = (d + s == v[0] << 1);
                else if (((d - s) >> 1) % g == 0)
                    pos = true;
                else
                {

                    d = (d + s) >> 1;
                    for (size_t i = 0; i < t; ++i)
                        if (d - v[i] % g == 0)
                            pos = true, i = t;
                }
            }

            if (pos)
                ans[j++] = 'Y';
            else
                ans[j++] = 'N';
        }

        for (size_t i = 0; i < j - 1; ++i)
            printf("%c ", ans[i]);

        printf("%c\n", ans[j - 1]);
    }

    return 0;
}

int gcd(int a, int b)
{

    while (b != 0)
    {

        int aux = a;
        a = b;
        b = aux % b;
    }

    return a;
}

int compare(const void *a, const void *b)
{

    return *(int *)a - *(int *)b;
}
