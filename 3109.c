/*

    @author: Malbolge;
    @date: 07/07/2020;
    @name: Trocando de Mesa;
*/

#include <stdio.h>

int main(int argc, char **argv)
{

    int t[1010];
    int n, q, c, a, b, ans;

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; ++i)
        t[i] = i;

    while (q--)
    {

        scanf("%d %d", &c, &a);

        if (c == 1)
        {

            scanf("%d", &b);

            ans = t[a];
            t[a] = t[b];
            t[b] = ans;
        }
        else
        {

            ans = 0;
            b = t[a];

            while (a != b)
                b = t[b], ++ans;

            printf("%d\n", ans);
        }
    }

    return 0;
}