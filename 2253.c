#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void main (void)
{


	unsigned short caracteresEspeciais = 0, tam, minuscula = 0, maiuscula = 0, tamanho = false;
	char senha[100];
	unsigned short i, casos = 10;

	while (casos)
	{
		scanf("%[^\n]", senha);
	
		tam = strlen(senha);

		if (tam >= 6 && tam <= 32)
			tamanho = true;
		else
			tamanho = false;

		for (i = 0; i < tam; i++)
			if (isupper(senha[i]) != 0)
				maiuscula++;
			else if (islower(senha[i]) != 0)
				minuscula++;
			else if (senha[i] >= 32 && senha[i] <= '/')
				caracteresEspeciais++;


		if (tamanho == true && maiuscula >= 1 && minuscula >= 1 && caracteresEspeciais != 0)
			printf("Senha inválida!\n");
		else
			printf("Senha Válida!\n");

	casos--;
	printf("%hu\n", casos);
	}
	
}