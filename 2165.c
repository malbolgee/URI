#include <stdio.h>

void main ()
{

	unsigned short qtsCaracteres, i;
	char texto[510];

	scanf("%[^\n]", texto);

	i = 0;
	while (texto[i++])
		qtsCaracteres++;


	if (qtsCaracteres > 140)
		printf("MUTE\n");
	else
		printf("TWEET\n");

}
