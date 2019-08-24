/*
    @autor: Malbolge;
    @data: 23/08/2019;
    @nome: Substituição de Tag;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

void solve();

int num;
char tag[15];
char string[60];

int main(int argc, char **argv)
{

    while (scanf("%s%d%*c%[^\n]", tag, &num, string) != EOF)
        solve();

    return 0;

}

void solve()
{

    int i = 0;
    int len = strlen(tag);

    while (string[i])
    {

        while (string[i] != '<' && string[i])
            putchar_unlocked(string[i++]);

        while (string[i] != '>' && string[i])
        {

            if (toupper(string[i]) == toupper(tag[0]))
                if (strncasecmp(&string[i], tag, len) == 0)
                    printf("%d", num), i += len;
                else
                    putchar_unlocked(string[i++]);
            else
                putchar_unlocked(string[i++]);
                    
        }

    }

    putchar_unlocked('\n');
    
}