/*
    @autor: Malbolge;
    @data: 23/03/2019;
    @nome: Fila do SUS;
*/

#include <stdio.h>

#define true 1
#define false 0

void main ()
{

    short i, ans;
    short hora, minuto, critico, n;

    while (scanf("%hd", &n) != EOF)
    {   

        ans = 0;
        short tempo_total = 420;
        for (i = 0; i < n; ++i)
        {

            scanf("%hd %hd %hd", &hora, &minuto, &critico);

            while (tempo_total < (hora * 60) + minuto)
                tempo_total += 30;
            
            if (tempo_total - ((hora * 60) + minuto) > critico)
                ++ans;

            tempo_total += 30;

        }

         printf("%hd\n", ans);
        
    }

}