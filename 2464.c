/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Decifra;
*/

#include <stdio.h>

unsigned short posiLetraOriginal(char *, char);

void main ()
{

	unsigned short i;
	char cifra[27], original[] = "abcdefghijklmnopqrstuvwxyz";
	char textoCifrado[10100], textoDecifrado[10100];

	scanf("%s", cifra);
	scanf("%s", textoCifrado);

	i = 0;
	while (textoCifrado[i])
	{
		// a função posiLetraOriginal() procura a posição da letra do texto
		// cifrado  dentro do alfabeto cifrado. Uma vez que as letras foram
		// apenas trocadas de lugar, quem estiver na posição, 2, por exemplo,
		// no alfabeto cifrado "zc'b'edfghljkinmypqrutsvwxoa". Eu sei que deveria ser
		// A letra 'c', pois no alfabeto original, quem está nessa posição é o c,
		// Por isso, a posição da letra errada no alfabeto cifrado é retornada como
		// índice no alfabeto original, que irá retornar então, a letra correta;
		textoDecifrado[i] = original[posiLetraOriginal(cifra, textoCifrado[i])];
		i++;

	}

	textoDecifrado[i] = '\0';
	printf("%s\n", textoDecifrado);

}

unsigned short posiLetraOriginal(char *cifra, char letra)
{

	unsigned short i;

	i = 0;

	while (cifra[i])
	{

		if (cifra[i] == letra)
			return i;

		i++;

	}

}
