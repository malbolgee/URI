/*

    @author: Malbolge;
    @date: 18/03/2020;
    @name: Fatorial;

*/

#include <stdio.h>
#include <unistd.h>

typedef unsigned uint;

int main(int argc, char **argv)
{

    uint n, x;
    uint fats[] = {1, 2, 6, 24, 120, 720, 5040, 40320};

    scanf("%u", &n);

    x = 0;
    for (int i = 7; i >= 0; --i)
        x += n / fats[i], n %= fats[i];

    printf("%u\n", x);

    return 0;

}