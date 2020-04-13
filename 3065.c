/*

    @author: Malbolge;
    @date: 09/04/2020;
    @name: Calculando;

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZ 11234

int main(int argc, char **argv)
{

    int n, x, ans, i, j;
    bool signal[MAXSIZ];

    x = 0;
    while (scanf("%d", &n), n)
    {   

        char *tmp;
        char string[MAXSIZ];
        int nums[MAXSIZ];

        scanf("%s", string);

        if (n == 1)
            printf("Teste %d\n%s\n\n", ++x, string);

        else
        {

            i = j = 0;
            while (string[i])
            {

                if (string[i] == '+')
                    signal[j++] = true;
                else if (string[i] == '-')
                    signal[j++] = false;

                ++i;

            }

            i = 0;
            tmp = strtok(string, "+-");
            nums[i++] = atoi(tmp);

            do
            {

                tmp = strtok(NULL, "+-");
                if (tmp)
                    nums[i++] = atoi(tmp);

            } while (tmp);
            
            ans = nums[0];
            for (i = 0; i < n - 1; ++i)
                if (signal[i])
                    ans += nums[i + 1];
                else
                    ans -= nums[i + 1];

            printf("Teste %d\n%d\n\n", ++x, ans);

        }

    }
    
    return 0;

}