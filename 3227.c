/*

    @author: Malbolge;
    @date: 13/06/2021;
    @problem: Doorman;
    @subject: Simulation;

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLEN 123

int main()
{

    int n;
    char string[MAXLEN] = {0};

    scanf("%d", &n);
    scanf("%s", string);

    int ans = 0;
    int cnt = 0;

    for (int i = 0; string[i]; ++i)
    {

        if (string[i] == 'M')
            ++cnt;
        else
            --cnt;

        if (abs(cnt) > n + 1)
        {

            ans = i - 1;
            break;
        }
    }

    if (ans == 0)
    {
        if (abs(cnt) > n)
            ans = strlen(string) - 1;
        else
            ans = strlen(string);
    }

    printf("%d\n", ans);

    return 0;
}