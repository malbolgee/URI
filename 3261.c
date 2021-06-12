/*

    @author: Malbolge;
    @date: 12/06/2021;
    @problem: Replicação de Vírus;
    @Subject: [String, Greedy];

*/

#include <stdio.h>
#include <string.h>

#define MAXSIZE 112345

static inline int max(int a, int b)
{

    return a > b ? a : b;
}

int main()
{

    char string1[MAXSIZE] = {0};
    char string2[MAXSIZE] = {0};

    scanf("%s", string1);
    scanf("%s", string2);

    int i = 0, j = 0;
    size_t s1len = strlen(string1);
    size_t s2len = strlen(string2);

    while (i < s1len && i < s2len && string1[i] == string2[i])
        ++i;

    while (j < s1len && j < s2len && string1[s1len - 1 - j] == string2[s2len - 1 - j])
        ++j;

    j = s2len - j;
    int ans = max(j - i, 0);

    printf("%d\n", max(ans, s2len - s1len));

    return 0;
}