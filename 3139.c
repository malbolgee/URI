/*
    @author: Tiago, Nilson and Malbolge;
    @date: 10/11/2020;
    @name: Buscando Novos Seguidores;
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

    long long cur, goal;
    long long sub[30] = {0};

    scanf("%lld %lld", &cur, &goal);

    long long sum = 0;
    for (size_t i = 0; i < 30; ++i)
        scanf("%lld", &sub[i]), sum += sub[i];

    long long mean = 0;
    long long days = 0;

    while (cur < goal)
    {

        for (size_t i = 0; i < 30 && cur < goal; ++i)
        {
            mean = ceil(sum / 30.0);
            cur += mean;
            sum = sum + (mean - sub[i]);
            sub[i] = mean;
            ++days;
        }
    }

    printf("%lld\n", days);

    return 0;
}