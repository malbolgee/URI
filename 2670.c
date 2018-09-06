/*
	@autor: Malbolge;
	@data: 05/09/2018;
	@nome: Máquina de Café;
*/


#include <stdio.h>

void main (void)
{

	unsigned short primeiroAndar, segundoAndar, terceiroAndar;
	unsigned short i, menor;
	short vet[5];

	scanf("%hu %hu %hu", &primeiroAndar, &segundoAndar, &terceiroAndar);

	vet[0] = segundoAndar*2 + terceiroAndar*4;
	vet[1] = primeiroAndar*2 + terceiroAndar*2;
	vet[2] = primeiroAndar*4 + segundoAndar*2;

	menor = vet[0];

	for (i = 0; i < 3; i++)
	{
		if (vet[i] < menor)
			menor = vet[i];
	}

	printf("%hu\n", menor);


}	