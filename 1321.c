/*
    @author: Malbolge;
    @date: 08/11/2020;
    @name: Jollo;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool cn[3];
int w[2][3];

bool solve(int, int);

int main(int argc, char **argv)
{

    while (scanf("%d %d %d %d %d", &w[0][0], &w[0][1], &w[0][2], &w[1][0], &w[1][1]), w[0][0])
    {

        bool ps;
        size_t i = 0;
        for (i = 1; i <= 52; ++i)
        {

            ps = true;
            for (size_t k = 0; k < 3; ++k)
                if (w[0][k] == i)
                    ps = false;

            for (size_t k = 0; k < 2; ++k)
                if (w[1][k] == i)
                    ps = false;

            if (!ps)
                continue;

            w[1][2] = i;
            memset(cn, 0, sizeof(cn));

            if (solve(0, 0))
                break;
        }

        if (i == 53)
            puts("-1");
        else
            printf("%ld\n", i);
    }

    return 0;
}

bool solve(int idx, int c)
{

    if (idx == 3)
        return c >= 2;

    for (size_t i = 0; i < 3; ++i)
    {

        if (cn[i])
            continue;

        cn[i] = true;
        if (!solve(idx + 1, c + (w[1][idx] > w[0][i] ? 1 : 0)))
            return false;

        cn[i] = false;
    }

    return true;
}