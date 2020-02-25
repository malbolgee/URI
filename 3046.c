/*

    @author: Malbolge;
    @date: 20/02/2020;
    @name: Dominó;

*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int n;

    scanf("%d", &n);

    printf("%d\n", ((n + 1) * (n + 2)) / 2);

    return 0;

}