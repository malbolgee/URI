/*

    @author: Malbolge;
    @date: 20/02/2020;
    @name: A Árvore de Natal;

*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int n, h, d, g;

    scanf("%d", &n);

    for (int i = 0 ; i < n; ++i)
    {

        scanf("%d %d %d", &h, &d, &g);

        if (h >= 200 && h <= 300)
            if (d >= 50)
                if (g >= 150)
                {
                    puts("Sim");
                    continue;
                }

        puts("Nao");

    }

    return 0;

}