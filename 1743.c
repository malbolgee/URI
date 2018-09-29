/*
	@autor: Malbolge;
	@data: 29/09/2018;
	@nome: Máquina de Verificação Automatizada;
*/

#include <stdio.h>
#include <stdbool.h>

bool plug(short macho[], short femea[], short tamM, short tamF);

void main ()
{

	short macho[5], femea[5];
	unsigned short i;


	for(i = 0; i < 5; i++)
		scanf("%hu", &macho[i]);
	for(i = 0; i < 5; i++)
		scanf("%hu", &femea[i]);

	if (plug(macho, femea, 5, 5))
		printf("Y\n");
	else
		printf("N\n");


}

bool plug(short macho[], short femea[], short tamM, short tamF)
{

	unsigned short i, j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		// Caso as entradas sejam iguais nas mesmas posições
		// os plugs não são compatíveis;
		if(macho[i] == femea[j])
			return false;

		i++;
		j++;

	}

	return true;

}
