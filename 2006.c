/*
	@autor: Malbolge;
	@data: 10/08/2018;
	@nome: Identificando o Chá;
*/

#include <stdio.h>

int main ()
{

	unsigned short int t, resposta, certo = 0;
	short respostas[5];

	scanf("%hd", &t);

	for (unsigned short i = 0; i < 5; i++)
		scanf("%hd", &respostas[i]);

	for (unsigned short i = 0; i < 5; i++)
		if (respostas[i] == t)
			certo++;

	printf("%d\n", certo);

}
