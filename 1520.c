/*
	@autor: Nilson Andrade;
	@data: 31/05/2019;
	@nome: Parafusos e Porcas;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

char scanff(int *a);

int main()
{

	int acl;
	int vet[101];
	int i, j, inicio, fim, iter;

	while (scanff(&iter) != EOF)
	{

		memset(vet, 0, sizeof(vet));

		for(j = 0; j < iter; j++)
        {

			scanf("%d %d", &inicio, &fim);
				
			for(i = inicio; i <= fim; i++)
				++vet[i];

		}

		acl = 0;
		scanf("%d", &j);

		if(vet[j])
        {

			for(i = 1; i < j; i++)
				acl += vet[i];

			printf("%d found from %d to %d\n", j, acl, (acl + vet[i] - 1));

		}
		else
			printf("%d not found\n", j);

	}

	return 0;

}
