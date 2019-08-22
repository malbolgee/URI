/*
    @autor: Malbolge;
    @data: 21/08/2019;
    @nome: Processador Amigável de Inteiros;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

char str[60];
char _str[60];

typedef long long ll;

void solve();
_Bool check();
_Bool zeros();
_Bool overflow();
char * takeZeros();

int main(int argc, char **argv)
{

    _Bool u, v, w;
    while (fgets(str, 60, stdin) != NULL)
    {

        int len = strlen(str) - 1;

        if (str[len] == '\n')
            str[len] = 0;

        solve();
        u = check();
        v = zeros();
        w = overflow();

        if (u || w || strlen(_str) < 1)
            puts("error");
        else if (v)
            puts("0");
        else
            printf("%s\n", takeZeros());

    }

    return 0;

}

_Bool overflow()
{

    ll x = atoll(_str);
    return x > 2147483647LL ? true : false;

}

_Bool check()
{

    int i = 0;
    while (_str[i])
    {

        if (_str[i] < 48 || _str[i] > 57)
            return true;

        ++i;

    }

    return false;

}

_Bool zeros()
{

    int i = 0;
    while (_str[i])
        if (_str[i++] != '0')
            return false;

    return true;

}

char * takeZeros()
{

    int i = 0, j = 0;
    char tmp[60] = { 0 };

    while (_str[i] == '0')
        ++i;

    while (_str[i])
        tmp[j++] = _str[i++];

    tmp[j] = 0;

    memset(_str, 0, sizeof(_str));
    memcpy(_str, tmp, j);

    return _str;

}

void solve()
{

    int i, j;

    i = j = 0;
    while (str[i])
    {

        if (str[i] == 'l')
            _str[j++] = '1', ++i;
        else if (str[i] == 'o' || str[i] == 'O')
            _str[j++] = '0', ++i;
        else if (str[i] == ',' || str[i] == ' ')
            ++i;
        else
            _str[j++] = str[i++];

    }

    _str[j] = 0;

}