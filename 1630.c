/*
    @author: Malbolge;
    @date: 10/07/2020;
    @name: Estacas;
*/

#include <stdio.h>

int gcd(int, int);
void solve(int, int);

int main(int argc, char **argv)
{

    int x, y;
    while (~scanf("%d %d", &x, &y))
        solve(x, y);

    return 0;
}

int gcd(int a, int b)
{

    int r = a % b;

    if (r == 0)
        return b;

    return gcd(b, r);
}

inline void solve(int x, int y)
{

    int mdc = gcd(x, y);
    printf("%d\n", ((x / mdc) * 2) + ((y / mdc) * 2));
}