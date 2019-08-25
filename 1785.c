/*
    @autor: Malbolge;
    @data: 25/08/2019;
    @nome: Kaprekar;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

void to_string();
void to_array(int);
int compare1(int *, int *);
int compare2(int *, int *);

int vetM[10], vetMM[4];
char numM[5], numMM[5];

int main(int argc, char **argv)
{

    _Bool flag;
    int n, c, x, p; 

    c = 0;
    scanf("%d%*c", &n);

    while (n--)
    {

        p = 0;
        flag = false;
        scanf("%d", &x);
        while (x != 6174)
        {

            to_array(x);

            qsort(vetM, 4, sizeof(int), compare1);
            qsort(vetMM, 4, sizeof(int), compare2);

            to_string();

            x = atoi(numMM) - atoi(numM);

            if (x == 0)
                flag = true;

            ++p;

            if (flag)
                break;

        }

        if (!flag)
            printf("Caso #%d: %d\n", ++c, p);
        else
            printf("Caso #%d: %d\n", ++c, -1);

    }

    return 0;

}

void to_string()
{

    int i;
    for (i = 0; i < 4; ++i)
    {

        numM[i] = (char)(vetM[i] + 48);
        numMM[i] = (char)(vetMM[i] + 48);

    }

}

void to_array(int x)
{

    int i = 3;
    memset(vetM, 0, sizeof(vetM));
    memset(vetMM, 0, sizeof(vetMM));
    
    while (x)
    {

        vetM[i] = vetMM[i] = x % 10;
        x /= 10;
        --i;

    }

}

int compare1(int *a, int *b)
{

    return *a - *b;
    
}

int compare2(int *a, int *b)
{

    return *b - *a;

}