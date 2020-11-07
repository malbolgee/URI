/*

    @author: Malbolge;
    @date: 06/11/2020;
    @name: Cultivando Strings;

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZES 1129
#define MAXSIZE 1000009
#define MAXSIZEM 10009

int cn = 1;

int x[MAXSIZE];
int y[MAXSIZEM];
int l[MAXSIZE];
int f[MAXSIZE << 2];
int trie[MAXSIZE][26];

typedef struct _string
{

    char string[MAXSIZES];

} string_t;

string_t string[MAXSIZEM];

int aho();
int solve(char *);
void push(int, char *);
int compare(const void *, const void *);

int max(int a, int b);

int main(int argc, char **argv)
{

    int n;
    int ans;

    while (scanf("%d", &n), n)
    {

        cn = 1;
        for (size_t i = 0; i < n; ++i)
            scanf("%s", string[i].string), y[i + 1] = 0;

        qsort(string, n, sizeof(string_t), compare);

        // for (size_t i = 0; i < n; ++i)
        //     printf("%s\n", string[i].string);

        for (size_t i = 0; i < n; ++i)
            push(i + 1, string[i].string);

        aho();

        ans = 1;
        y[1] = 1;

        for (size_t i = 1; i < n; ++i)
            ans = max(ans, y[i + 1] = solve(string[i].string));

        printf("%d\n", ans);

        for (size_t i = 0; i < cn; ++i)
        {

            x[i] = l[i] = 0;
            for (size_t j = 0; j < 26; ++j)
                trie[i][j] = 0;
        }
    }

    return 0;
}

int compare(const void *a, const void *b)
{

    return strlen(((string_t *)a)->string) > strlen(((string_t *)b)->string);
}

void push(int idx, char *s)
{

    int n = 0;
    size_t size = strlen(s);
    for (size_t i = 0; i < size; ++i)
    {

        int c = s[i] - 'a';
        if (!trie[n][c])
            trie[n][c] = cn++;

        n = trie[n][c];
    }

    x[n] = idx;
}

int aho()
{

    int start, end;
    start = end = 0;

    f[end++] = 0;

    while (start < end)
    {

        int w = f[start++];
        x[w] = max(x[w], x[l[w]]);

        for (size_t i = 0; i < 26; ++i)
        {

            if (trie[w][i])
            {

                int z = trie[w][i];
                f[end++] = z;
                l[z] = w ? trie[l[w]][i] : 0;
            }
            else
                trie[w][i] = trie[l[w]][i];
        }
    }
}

int solve(char *s)
{

    int n = 0;
    int ans = 0;

    for (size_t i = 0; s[i]; ++i)
    {

        n = trie[n][s[i] - 'a'];
        ans = max(ans, max(y[x[n]], y[x[l[n]]]));
    }

    return ans + 1;
}

inline int max(int a, int b)
{

    return a > b ? a : b;
}