/*
	@autor: Malbolge;
	@data: 19/08/2019;
	@nome: Calouro Vence Veterano?;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

typedef long long ll;

typedef struct {

	char s[15];

} string;

ll ans;
string v[MAXSIZE];

void merge(string *, ll, ll *);

int main(int argc, char **argv)
{
    
	ll n, i;
	while (scanf("%lld", &n) != EOF)
	{

		i = ans = 0;

		while (n--)
			scanf("%s[^/]%*s", v[i++].s);

		merge(v, i, &ans);
		printf("%lld\n", ans);

	}

	return 0;

}

void merge(string *a, ll n, ll *inv)
{

	if (n > 1LL)
	{

		merge(a, n >> 1LL, inv);
		merge(a + (n >> 1LL), (n + 1LL) >> 1LL, inv);
		ll i = 0LL, k;
		ll j = n >> 1LL;
		string b[n];

		for (k = 0LL; k < n; ++k)
		{

			if (i < (n >> 1LL) && j < n)
			{

				if (strcmp(a[i].s, a[j].s) < 0)
					b[k] = a[i], ++i;
				else if (strcmp(a[j].s, a[i].s) < 0)
					strcpy(b[k].s, a[j].s), ++j, *inv += (n >> 1LL) - i;
				else
					strcpy(b[k].s, a[i].s), ++i;
				
			}
			else if (i < (n >> 1LL))
				strcpy(b[k].s, a[i].s), ++i;
			else
				strcpy(b[k].s, a[j].s), ++j;

		}

		memcpy(a, b, sizeof(string) * n);

	}

}
