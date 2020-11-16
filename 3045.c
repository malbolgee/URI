/*
    @author: Malbolge;
    @date: 15/11/2020;
    @name: Parque Jurássico;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 1500
#define min(a, b) (((a) < (b)) ? (a) : (b))

int lens;
int lent;
char t[MAXSIZE];
char s[MAXSIZE / 10];
char res[MAXSIZE];
int dp[MAXSIZE / 10 + 1][MAXSIZE / 10 + 1];

int solve(int, int);
void back(int, int);

int indexx;

int main(int argc, char **argv)
{

    size_t test = 0;
    while (scanf("%s", s), s[0] != '#')
    {

        scanf("%s", t);

        lens = strlen(s);
        lent = strlen(t);

        indexx = 0;
        memset(dp, -1, sizeof(dp));
        memset(res, 0, sizeof(res));

        solve(0, 0);
        back(0, 0);

        printf("Teste %ld\n%s\n\n", ++test, res);
    }

    return 0;
}

int solve(int ps, int pt)
{

    if (ps == lens && pt == lent)
        return 0;

    if (dp[ps][pt] != -1)
        return dp[ps][pt];

    int ans = 1 << 30;
    if (ps < lens)
        ans = min(ans, solve(ps + 1, pt) + 1);
    if (pt < lent)
        ans = min(ans, solve(ps, pt + 1) + 1);

    if (ps < lens && pt < lent && s[ps] == t[pt])
        ans = min(ans, solve(ps + 1, pt + 1) + 1);

    return dp[ps][pt] = ans;
}

void back(int ps, int pt)
{

    if (ps == lens && pt == lent)
        return;

    int ep = dp[ps][pt];

    if (ps < lens && pt < lent && s[ps] == t[pt] && ep == solve(ps + 1, pt + 1) + 1)
    {
        res[indexx++] = s[ps];
        back(ps + 1, pt + 1);
        return;
    }

    if (ps < lens)
        if (ep == solve(ps + 1, pt) + 1)
        {
            res[indexx++] = s[ps];
            back(ps + 1, pt);
            return;
        }

    if (pt < lent)
        if (ep == solve(ps, pt + 1) + 1)
        {
            res[indexx++] = t[pt];
            back(ps, pt + 1);
            return;
        }

    return;
}
