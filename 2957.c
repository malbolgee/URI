/*
    @autor: Malbolge;
    @data: 26/09/2019;
    @nome: Sir Vô;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0
#define MAXSIZE 100

typedef struct _string{

    char s[MAXSIZE];
    int sz;

} string_t;

char vis[200];
int compare(string_t *, string_t *);

int main(int argc, char **argv)
{

    char c;
    int n, k, i, j;

    scanf("%d %d%*c", &n, &k);

    string_t string[MAXSIZE];

    for (i = 0; i < n; ++i, j = 0)
    {

        do
        {
            
            c = getchar_unlocked();
            if (c != ' ' && c != '\n')
                string[i].s[j++] = c;

        } while (c != '\n');

        string[i].s[j] = '\0';
        string[i].sz = strlen(string[i].s);

    }

    qsort(string, n, sizeof(string_t), compare);

    j = i = 0;
    int ans = 0;

    while (j < k && i < n)
    {

        if (!vis[tolower(string[i].s[0])])
            ans += string[i].sz, vis[tolower(string[i].s[0])] = true, ++j;

        ++i;

    }

    printf("%d\n", ans);

    return 0;

}

int compare(string_t *a, string_t *b)
{

    return strlen(b->s) - strlen(a->s);

}