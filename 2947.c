/*

	@autor: Malbolge;
	@data: 16/07/2019;
	@nome: Gabarito;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 110

char ans[MAXSIZE][MAXSIZE];

int main(int argc, char **argv)
{

	char des[MAXSIZE];
	int qtsQ, qtsC, i, j, res;
	int maior, maior_s, idx_m;

	scanf("%d", &qtsQ); scanf("%s", des); scanf("%d", &qtsC);

	for (i = 0; i < qtsC; ++i)
		scanf("%s", ans[i]);

	res = 0;
	int freq[100] = { 0 };
	
	for (i = j = 0; i < qtsQ; ++i, j = 0)
	{

		memset(freq, 0, sizeof(freq));

		while (j < qtsC)
			freq[ans[j++][i]]++;

		idx_m = 'A';
		maior_s = -1;
		maior = freq['A'];
		for (j = 'B'; j <= 'Z'; ++j)
		{

			if (freq[j] > maior)
			{

				idx_m = j;
				maior_s = maior;
				maior = freq[j];

			}
			else if (freq[j] > maior_s)
				maior_s = freq[j];

		}

		if (des[i] == idx_m)
			res += maior_s;
		else
			res += maior;
		
	}

	printf("%d\n", res);

	return 0;

}