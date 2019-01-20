/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Balé;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

int bit[MAXSIZE + 10];

int get(int);
int update(int);

void main ()
{

	int n, i, tmp;
	scanf("%d", &n);

	memset(bit, 0, sizeof(bit));
	long long ans = 0;

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		update(tmp);
		ans += get(MAXSIZE) - get(tmp);
	}

	printf("%lld\n", ans);

}


int get(int x)
{

	int retorno = 0;
	for (; x; x -= x&-x)
		retorno += bit[x];

	return retorno;
}

int update(int x)
{

	for (; x < MAXSIZE; x += x&-x)
		bit[x]++;

}
