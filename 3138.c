/*
    @author: Malbolge;
    @date: 03/11/2020;
    @name: Aniversário do Tobias;
*/

#include <stdio.h>
#include <string.h>

typedef struct cores
{

    int qts;
    long long hash;

} cores_t;

long long hash(const char *);
int search(long long, size_t size, cores_t *);
unsigned long long factorial(unsigned long long);

int main(int argc, char **argv)
{

    int n;
    scanf("%d", &n);

    size_t i = 0UL;
    char cor[23] = {0};
    cores_t cores[23] = {0};
    int qts = 0;

    while (n--)
    {

        scanf("%s %d", cor, &qts);

        long long _hash = hash(cor);
        int x = search(_hash, i, cores);

        if (x >= 0)
            cores[x].qts += qts;
        else
            cores[i].hash = _hash, cores[i++].qts = qts;
    }

    unsigned long long sum = 1LLU;
    unsigned long long total = 0LLU;
    for (size_t j = 0UL; j < i; ++j)
        sum *= factorial(cores[j].qts), total += cores[j].qts;

    puts("Feliz aniversario Tobias!");
    printf("%llu\n", factorial(total) / sum);

    return 0;
}

unsigned long long factorial(unsigned long long n)
{

    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}

long long hash(const char *string)
{

    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;

    for (size_t i = 0; string[i]; ++i)
    {
        hash_value = (hash_value + (string[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }

    return hash_value;
}

int search(long long hash, size_t size, cores_t *cores)
{

    for (size_t i = 0; i < size; ++i)
        if (hash == cores[i].hash)
            return i;

    return -1;
}