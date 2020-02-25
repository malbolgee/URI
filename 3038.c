/*

    @author: Malbolge;
    @date: 21/02/2020;
    @name: Carta de Natal Criptografada;

*/


#include <stdio.h>

int main(int argc, char **argv)
{

    char string[300];

    while (~scanf("%[^\n]%*c", string))
    {

        for (int i = 0; string[i]; ++i)
            if (string[i] == '@')
                putchar_unlocked('a');
            else if (string[i] == '&')
                putchar_unlocked('e');
            else if (string[i] == '!')
                putchar_unlocked('i');
            else if (string[i] == '*')
                putchar_unlocked('o');
            else if (string[i] == '#')
                putchar_unlocked('u');
            else
                putchar_unlocked(string[i]);
        
        putchar_unlocked('\n');

    }

    return 0;

}