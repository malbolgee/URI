/*
	@autor: Malbolge;
	@data: 24/12/2018;
	@nome: Getline Two - Frutas;
*/

#include <stdio.h>
#include <string.h>

float kilos(char *);

void main ()
{

	char lixo;
	char fruta[10000] = { 0 };
	unsigned short casos, i, kilo;
	float preco, mediaKilo, mediaPreco;

	scanf("%hu", &casos);
	scanf("%c", &lixo);

	mediaKilo = mediaPreco = 0;
	for (i = 0; i < casos; ++i)
	{

		scanf("%f", &preco);
		mediaPreco += preco;
		scanf("%c", &lixo);

		fgets(fruta, 10000, stdin);
		kilo = kilos(fruta);
		mediaKilo += kilo;

		printf("day %hu: %hu kg\n", i + 1, kilo);

	}

	printf("%.2f kg by day\n", mediaKilo / (casos * 1.0f));
	printf("R$ %.2f by day\n", mediaPreco / casos * 1.0f);

}

float kilos(char *fruta)
{

	char *tmp;
	unsigned short qtsFrutas = 0;

	tmp = strtok(fruta, " ");
	qtsFrutas++;

	do
	{

		tmp = strtok('\0', " ");

		if (tmp)
			qtsFrutas++;

	} while (tmp);

	return qtsFrutas;

}
