/*

    @author: Malbolge;
    @date: 06/11/2020;
    @name: Contagem de Dígitos; 
    @https://stackoverflow.com/questions/2059680/how-to-count-each-digit-in-a-range-of-integers
*/

#include <stdio.h>

int solve(int, int);

int main(int argc, char **argv)
{

    int a, b;
    while (scanf("%d %d", &a, &b), a)
    {

        for (int i = 0; i < 9; ++i)
            printf("%d ", solve(b, i) - solve(a - 1, i));

        printf("%d\n", solve(b, 9) - solve(a - 1, 9));
    }

    return 0;
}

int solve(int n, int d)
{

    int ans, p, l, pv;

    p = 1;
    ans = l = pv = 0;

    while (n > 0)
    {

        int x = n % 10;
        n /= 10;

        ans += x * pv * p / 10;

        if (x > d)
            ans += p;
        else if (x == d)
            ans += l + 1;

        l += p * x;
        p *= 10;
        ++pv;
    }

    if (d == 0)
        ans -= (p - 1) / 9;

    return ans;
}
