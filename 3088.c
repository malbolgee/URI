/*
    @author: Malbolge;
    @date: 21/06/2020;
    @name:Correção de Texto;
*/

#include <stdio.h>

#define MAX 12345

int main(int argc, char **argv)
{

    char string[MAX];
    while (~scanf("%[^\n]%*c", string))
    {

        int i = 0;
        while (string[i])
        {

            if (string[i] == ' ')
                if (string[i + 1] == ',' || string[i + 1] == '.')
                    putchar_unlocked(string[i + 1]), ++i;
                else
                    putchar_unlocked(string[i]);
            else
                putchar_unlocked(string[i]);

            ++i;

        }

        putchar_unlocked('\n');

    }

    return 0;
}