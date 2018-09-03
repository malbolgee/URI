#include <stdio.h>
#include <string.h>

void main (void)
{

	char bacDNA[110], restDNA[110];
	unsigned short contador = 0, restDnaTam, bacDnaTam, j = 0, i = 0;

	while (scanf("%s %s", bacDNA, restDNA) != EOF)
	{

		restDnaTam = strlen(restDNA);
		bacDnaTam = strlen(bacDNA);
		contador = 0;
		printf("%hu\n", restDnaTam);
		
		while (bacDnaTam--)
		{
			printf("Valor atual de restDNA na posição %hu: %c\n", j, restDNA[j]);
			printf("Valor da bacDNA na posição %hu: %c\n", i, bacDNA[i]);
			if (bacDNA[i] == restDNA[j])
			{	

				contador++;
				j++;
				i++;
				printf("Esse o valor a tual de contador: %d\n", contador);
				if (contador == restDnaTam)
				{	
					printf("Resistente\n");
					break;
				}

			}
			else
			{
				i++;
				contador = 0;
				printf("Esse é o valor a atual de i: %hu\n", i);
				j = 0;
			}

		}

		printf("Esse é o valor atual de contador fora do laço: %hu\n", contador);
		printf("Testando: \n");

		if (contador != restDnaTam)
			printf("Nao resistente\n");

		contador = 0;
		i = 0;
		j= 0;
	}

}