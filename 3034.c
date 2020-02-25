/*

    @author: Malbolge;
    @date: 21/02/2020;
    @name: O Caso Douglas;

*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool prime(int);

int main(int argc, char **argv)
{

    int n, x;
    bool p, seven, even;

    scanf("%d", &n);

    while (n--)
    {

        scanf("%d", &x);
        
        ++x;
        p = prime(x + 2);
        even = x & 1 ? true : false;
        seven = !(x % 7) ? true : false;

        if (p && even && seven)
            puts("Yes");
        else
            puts("No");

    }

    return 0;

}

bool prime(int x)
{

    if (x % 2 == 0 && x != 2 || x == 1)
        return false;

    int max = sqrt(x);
    for (int i = 3; i <= max; i += 2)
        if (x % i == 0)
            return false;

    return true;

}