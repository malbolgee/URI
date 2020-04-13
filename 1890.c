/*

    @author: Malbolge;
    @date: 11/04/2020;
    @name: Emplacando os Tuk-tuks;

*/

#include <stdio.h>

typedef unsigned uint;
inline uint power(uint, uint);

int main(int argc, char **argv)
{

    uint n, x ,y;

    scanf("%d", &n);
    while (n--)
    {

        scanf("%d %d", &x, &y);

        if (!x && !y)
            puts("0");
        else if (!x)
            printf("%u\n", power(10, y));
        else if (!y)
            printf("%u\n", power(26, x));
        else
            printf("%u\n", power(10, y) * power(26, x));

    }

    return 0;

}

uint power(uint a, uint b)
{

    uint ans = 1;

    while (b--)
        ans *= a;

    return ans;

}