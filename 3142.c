/*
    @author: Malbolge;
    @date: 02/11/2020;
    @name: Excel Bugado;
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv)
{
    
    char string[20];
    while (~scanf("%s", string))
    {

        unsigned long long sum = 0UL;
        for (int i = strlen(string) - 1, j = 0; i >= 0; --i, ++j)
            sum += (string[i] - 'A' + 1) * (unsigned long long)pow(26, j);

        if (sum <= 16384)
            printf("%llu\n", sum);
        else
            puts("Essa coluna nao existe Tobias!");
    }

    return 0;
}