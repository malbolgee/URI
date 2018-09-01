/*
	@autor: Malbolge;
	@data: 31/08/2018;
	@nome: De Dentro para Fora;
*/

#include <stdio.h>
#include <string.h>

int main (){

	char texto[110],c;
	unsigned short tam, metadeTam;
	unsigned casos, i;

	scanf("%u", &casos);

	// Limpar o buffer para a próxima entrada;
	setbuf(stdin, NULL);

	while (casos)
	{	
		//"%[\^n]" para o problema dos espaços;
		scanf("%[^\n]", texto);

		// Limpar o buffer para o laço não entrar em um loop;
		setbuf(stdin, NULL);
		
		tam = strlen(texto);
		metadeTam = tam/2;

		for (i = metadeTam-1; i < -1; i--)
			printf("%c", texto[i]);

		for (i = tam-1; i >= metadeTam; i--)
			printf("%c", texto[i]);


		printf("\n");
		
	casos--;
	}
}