/*
	@autor: Malbolge;
	@data: 05/09/2018;
	@nome: Língua do P;
*/

#include <stdio.h>

void main (void)
{

	char texto[1100], caractere;
	unsigned  i = 0;
	short impar = 0;


	//Pega caractere a caractere enquanto esse caractere não for um 'enter';
	do
	{

		scanf("%c", &caractere);

		//Caso o caractere da vez seja um espaço, desconsidere-o, mas o coloque na string final;
		if (caractere == ' ')
		{
			impar--;
			texto[i++] = caractere;

		}
		//Os caracteres sobressalentes 'p' sempre estão em posições ímpar na string;
		else if (impar % 2 != 0)
			texto[i++] = caractere;

		impar++;

	} while (caractere != '\n');

	texto[i] = '\0';
	printf("%s\n", texto);

}