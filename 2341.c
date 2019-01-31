/*
	@autor: Malbolge;
	@data: 30/01/2019;
	@nome: Número de Envelopes;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAX 1100
#define INF 0x3f3f3f3f3f
#define MIN(a, b) a < b ? a : b

unsigned rotulos[MAX];

int compara(unsigned *, unsigned *);

void main ()
{

	unsigned i;
	unsigned n, m, tmp, ans;

	scanf("%u %u", &n, &m);

	for (i = 0; i < n; ++i)
		scanf("%u", &tmp), rotulos[tmp]++;

	ans = INF;
	for (i = 1; i <= m; ++i)
		ans = MIN(ans, rotulos[i]);

	printf("%u\n", ans);

}
