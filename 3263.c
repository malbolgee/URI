/*

    @author: Malbolge;
    @date: 12/06/2021;
    @problem: Apague Com Segurança;
    @Subject: [Ad-Hoc, Xor];

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *flip(char *, size_t);
bool check(char *, char *, size_t);

int main()
{

    int n;
    char string1[1010] = {0};
    char string2[1010] = {0};

    scanf("%d", &n);
    scanf("%s", string1);
    scanf("%s", string2);

    size_t len = strlen(string1);

    if ((n % 2 == 1 && check(string1, flip(string2, len), len)) || (n % 2 == 0 && check(string1, string2, len)))
        puts("Deletion succeeded");
    else
        puts("Deletion failed");

    return 0;
}

bool check(char *s1, char *s2, size_t len)
{

    for (int i = 0; i < len; ++i)
        if (s1[i] != s2[i])
            return false;

    return true;
}

char *flip(char *s, size_t len)
{

    for (int i = 0; i < len; ++i)
        if (s[i] == '0')
            s[i] = '1';
        else
            s[i] = '0';

    return s;
}
