/*

    @author: Malbolge;
    @date: 26/02/2020;
    @name: 	Entrada e Saída Lendo e Pulando Nomes;

*/

#include <stdio.h>

int main(int argc, char **argv)
{

    char string[40];

    for (int i = 1; i <= 10; ++i)
    {

        scanf("%s", string);

        if (i == 3)
            puts(string);
        else if (i == 7)
            puts(string);
        else if (i == 9)
            puts(string);

    }

    return 0;

}