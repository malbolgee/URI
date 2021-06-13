/*

    @author: Malbolge;
    @date: 13/06/2021;
    @problem: Plantando Árvores;
    @subject: Greedy;

*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *, const void *b);

int main()
{

    int n;
    scanf("%d", &n);

    int vals[n];

    for (int i = 0; i < n; ++i)
        scanf("%d", &vals[i]);

    qsort(vals, n, sizeof(int), compare);

    int ans = vals[0] + 2;
    for (int i = 1; i < n; ++i)
        if (i + 2 + vals[i] > ans)
            ans = i + 2 + vals[i];

    printf("%d\n", ans);

    return 0;
}

int compare(const void *a, const void *b)
{

    return *(int *)b - *(int *)a;
}