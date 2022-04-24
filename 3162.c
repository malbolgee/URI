/*
    @author: Malbolge;
    @date: 10/02/2022;
    @problem: Comunicação Espacial;
    @subject: Iniciante;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int m[11][3];

int __always_inline min(int a, int b)
{
    return a < b ? a : b;
}

int __always_inline dist(int a, int b)
{
    return sqrt(pow((m[a][0] - m[b][0]), 2) + pow((m[a][1] - m[b][1]), 2) + pow((m[a][2] - m[b][2]), 2));
}

int main(int argc, char **argv)
{

    int n;
    scanf("%d", &n);
    memset(m, 0, sizeof(int) * n);

    for (int i = 0; i < n; ++i)
        scanf("%d %d %d", &m[i][0], &m[i][1], &m[i][2]);

    for (int i = 0; i < n; ++i)
    {
        int minimun = 0xFFFF;
        for (int j = 0; j < n; ++j)
            if (i != j)
                minimun = min(minimun, dist(i, j));

        if (minimun < 20)
            putchar_unlocked('A'), putchar_unlocked('\n');
        else if (minimun < 50)
            putchar_unlocked('M'), putchar_unlocked('\n');
        else
            putchar_unlocked('B'), putchar_unlocked('\n');
    }

    return 0;
}