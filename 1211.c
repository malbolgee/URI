/*
    @autor: Malbolge;
    @data: 28/05/2019;
    @nome: Lista Telefônica Econômica;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{

	char s1[250];

} string;

string sstring[100050];

int compare(string *, string *);

int main(int argc, char **argv)
{

	unsigned t, i, j;
	while (scanf("%d", &t) != EOF)
	{

		i = 0;
		unsigned aux = t;
		while (t--)
			scanf("%s", sstring[i++].s1);

		unsigned ans = 0;
		qsort(sstring, i, sizeof(string), compare);

		for (i = 1; i < aux; ++i)
			for (j = 0; sstring[i].s1[j]; ++j)
				if (sstring[i].s1[j] == sstring[i - 1].s1[j])
					++ans;
				else
					break;

		printf("%u\n", ans);
	}

	return 0;

}

int compare(string *a, string *b)
{

	int aux = strcmp(a->s1, b->s1);

	if (aux == 0)
		return 0;
	else if (aux < 0)
		return 1;
	else
		return -1;

}