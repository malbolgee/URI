/*	
	@autor: Malbolge;
	@data: 31/08/2018;
	@nome: Validador de Senhas;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void main (void)
{

	unsigned short caracteresEspeciais = 0, tam, minuscula = 0, maiuscula = 0, tamanho;
	char senha[1000];
	unsigned short i, casos = 10;


		while (scanf(" %[^\n]", senha) != EOF)
		{
	
			tam = strlen(senha);
			tamanho = true;

			if (6 > tam || tam > 32)
				tamanho = false;
			
			for (i = 0; i < tam; i++)
			{
				if (isupper(senha[i]) != 0)
					maiuscula++;
				else if (islower(senha[i]) != 0)
					minuscula++;
				else if ((senha[i] >= 32 && senha[i] <= '/') || senha[i] > 58 && senha[i] > 40)
					caracteresEspeciais++;
			}

			if (tamanho == true && maiuscula != 0 && minuscula != 0 && caracteresEspeciais == 0)
				printf("Senha valida.\n");
			else
				printf("Senha invalida.\n");

			maiuscula = 0;
			minuscula = 0;
			caracteresEspeciais = 0;
			memset(senha, 0, sizeof(senha));

		}
}