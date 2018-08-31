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
	//variável c recebe o \n do scanf de "casos";
	scanf("%c",&c);

	while (casos)
	{	
		//"%[\^n]" para o problema dos espaços;
		scanf("%[^\n]", texto);
		tam = strlen(texto);
		metadeTam = tam/2;

		for (i = metadeTam-1; i < -1; i--)
			printf("%c", texto[i]);

		for (i = tam-1; i >= metadeTam; i--)
			printf("%c", texto[i]);


		printf("\n");
		//o último \n vai para a variável C a fim resetar o buffer;
		//Caso contrário, laço entraria num loop;
		scanf("%c", &c);

	casos--;
	}
}