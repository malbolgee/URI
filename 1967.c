/*
    @autor: Malbolge;
    @data: 10/09/2019;
    @nome: A Fronteira Final;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0

int dig[2010];

int main(int argc, char **argv)
{

    int i, j, k;
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    int matrixA[a][b];
    int matrixB[b][c];
    int matrixC[c][d];

    for (i = 0; i < a; ++i)
        for (j = 0; j < b; ++j)
            scanf("%d", &matrixA[i][j]);
    
    for (i = 0; i < b; ++i)
        for (j = 0; j < c; ++j)
            scanf("%d", &matrixB[i][j]);

    int matrixAns[a][c];
    memset(matrixAns, 0, sizeof(matrixAns));

    for (i = 0; i < a; ++i)
        for (j = 0; j < c; ++j)
            for (k = 0; k < b; ++k)
                matrixAns[i][j] += matrixA[i][k] * matrixB[k][j];

    for (i = 0; i < c; ++i)
        for (j = 0; j < d; ++j)
            scanf("%d", &matrixC[i][j]);

    int ans[a][d];
    memset(ans, 0, sizeof(ans));

    for (i = 0; i < a; ++i)
        for (j = 0; j < d; ++j)
        {

            for (k = 0; k < c; ++k)
                ans[i][j] += matrixAns[i][k] * matrixC[k][j];

            if (ans[i][j] > dig[j])
                dig[j] = ans[i][j];

        }
    
    for (i = 0; i < a; ++i)
        for (j = 0; j < d; ++j)
            printf("%*d%c", (int)log10(dig[j] == 0 ? 1 : dig[j]) + 1, ans[i][j], j < d - 1 ? ' ' : '\n');
    
    return 0;

}
