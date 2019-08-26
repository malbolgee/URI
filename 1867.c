/*
    @autor: Malbolge;
    @data: 14/08/2019;
    @nome: Maior Número de Um Algarismo;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

char num1[1010];
char num2[1010];

int solve(char *);

int main(int argc, char **argv)
{

    while (true)
    {

        scanf("%s %s", num1, num2);

        if (strcmp(num1, "0") == 0 && strcmp(num2,"0") == 0)
            break;

        int x = solve(num1);
        int y = solve(num2);

        if (x > y)
            putchar_unlocked('1');
        else if (x < y)
            putchar_unlocked('2');
        else
            putchar_unlocked('0');

        putchar_unlocked('\n');

    }
    return 0;

}

int solve(char *str)
{

    int i, x;

    if (strlen(str) == 1)
        return (int)(str[0] - 48);

    i = x = 0;
    while (str[i])
        x += (int)(str[i++] - 48);

    i = 0;
    while (x)
        str[i++] = (char)((x % 10) + 48), x /= 10;

    str[i] = 0;

    return solve(str);

}