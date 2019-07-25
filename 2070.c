/*
    @autor: Malbolge;
    @data: 25/07/2019;
    @nome: Contando Sequências Boladas;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;
int l[3];
int s[3][205];
int g[3][205][25];
int m[205][205][205];
int cc[205][205][205];

typedef struct{

    int a, b, c;

} tri;

typedef struct{

    int first;
    int second;

} pair;

pair bfs();

int main(int argc, char **argv)
{

    int i, j, w;
    scanf("%d %d %d %d", &k, &l[0], &l[1], &l[2]);

    for (i = 0; i < 3; ++i)
        for (j = 1; j <= l[i]; ++j)
            scanf("%d", &s[i][j]);

    for (i = 0; i < 3; ++i)
        for (j = 1; j <= l[i]; ++j)
            for (w = 0; w <= k; ++w)
                g[i][j][w] = l[i] + 1;

    for (i = 0; i < 3; ++i)
        for (j = 1; j <= l[i]; ++j)
            for (w = j - 1; w >= 0; --w)
            {

                g[i][w][s[i][j]] = j;
                if (s[i][w] == s[i][j])
                    break;

            }

    pair ans = bfs();
    printf("%d %d\n", ans.first, ans.second);

    return 0;

}

pair bfs()
{

    int qts = 0;
    int i, s, e;
    int menor = 1000000;
    tri queue[100000];

    s = e = 0;
    tri tmp = { 0 };
    queue[e++] = tmp;

    memset(m, 0, sizeof(m));
    memset(cc, 0, sizeof(cc));

    cc[0][0][0] = 1;

    while (s < e)
    {

        int p1 = queue[s].a;
        int p2 = queue[s].b;
        int p3 = queue[s].c;

        s++;

        if (menor <= m[p1][p2][p3])
            break;

        for (i = 1; i <= k; ++i)
        {

            if (g[0][p1][i] == l[0] + 1 || g[1][p2][i] == l[1] + 1 || g[2][p3][i] == l[2] + 1)
                menor = m[p1][p2][p3] + 1, qts += cc[p1][p2][p3];
            if (qts)
                continue;

            int pp1 = g[0][p1][i];
            int pp2 = g[1][p2][i];
            int pp3 = g[2][p3][i];

            if (!m[pp1][pp2][pp3])
            {

                m[pp1][pp2][pp3] = m[p1][p2][p3] + 1;
                cc[pp1][pp2][pp3] = cc[p1][p2][p3];
                tri tmp = {pp1, pp2, pp3};
                queue[e++] = tmp;

            }
            else if (m[pp1][pp2][pp3] == m[p1][p2][p3] + 1)
                cc[pp1][pp2][pp3] += cc[p1][p2][p3];

        }

    }

    pair ans;
    ans.first = menor;
    ans.second = qts;

    return ans;

}